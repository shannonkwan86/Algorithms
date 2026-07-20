#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

struct AhoCorasick
{
    static constexpr int ALPHABET = 26;

    struct Node
    {
        int len;
        int link;
        array<int, ALPHABET> next;

        int term; // 如果该节点是某个询问串终点，记录询问串 id，否则 -1
        int up;   // 沿 fail/link 往上最近的询问串终点

        Node() : len{}, link{}, next{}, term(-1), up{} {}
    };

    vector<Node> t;

    AhoCorasick()
    {
        init();
    }

    void init()
    {
        t.assign(2, Node());

        // 0 是虚拟节点，1 是真正 root
        t[0].next.fill(1);
        t[0].len = -1;
    }

    int newNode()
    {
        t.emplace_back();
        return (int)t.size() - 1;
    }

    int add(const vector<int> &a)
    {
        int p = 1;

        for (auto x : a)
        {
            if (t[p].next[x] == 0)
            {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }

            p = t[p].next[x];
        }

        return p;
    }

    int add(const string &a, char offset = 'a')
    {
        vector<int> b(a.size());

        for (int i = 0; i < (int)a.size(); i++)
        {
            b[i] = a[i] - offset;
        }

        return add(b);
    }

    void work()
    {
        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            for (int i = 0; i < ALPHABET; i++)
            {
                if (t[x].next[i] == 0)
                {
                    // 没有真实 Trie 边：
                    // 继承 fail 状态的转移
                    t[x].next[i] = t[t[x].link].next[i];
                }
                else
                {
                    int y = t[x].next[i];

                    // 求儿子的 fail/link
                    t[y].link = t[t[x].link].next[i];

                    // up[y] = fail 链上最近的询问串终点
                    int f = t[y].link;

                    if (t[f].term != -1)
                    {
                        t[y].up = f;
                    }
                    else
                    {
                        t[y].up = t[f].up;
                    }

                    q.push(y);
                }
            }
        }
    }

    int next(int p, char c)
    {
        return t[p].next[c - 'a'];
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    string S;
    cin >> S;

    vector<long long> a(n + 1);
    vector<long long> pre(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    /*
        f(l, r) = pre[r] - pre[l - 1]

        对某个出现位置 p，长度 len：

        前一个出现位置为 last

        这一块：
        l ∈ [last + 1, p]
        r ∈ [p + len - 1, n]

        令 x = l - 1：

        x ∈ [last, p - 1]

        最大值：
        max pre[r] - min pre[x]
    */

    // sufMax[i] = max(pre[i...n])
    vector<long long> sufMax(n + 2, LLONG_MIN);

    for (int i = n; i >= 0; i--)
    {
        sufMax[i] = max(pre[i], sufMax[i + 1]);
    }

    /*
        需要 O(1) 查询：

        min(pre[l...r])

        用 ST 表。
    */

    int LOG = __lg(n + 1) + 1;

    vector<vector<long long>> st(
        LOG,
        vector<long long>(n + 1));

    st[0] = pre;

    for (int k = 1; k < LOG; k++)
    {
        for (int i = 0; i + (1 << k) <= n + 1; i++)
        {
            st[k][i] =
                min(
                    st[k - 1][i],
                    st[k - 1][i + (1 << (k - 1))]);
        }
    }

    auto rangeMin = [&](int l, int r) -> long long
    {
        int len = r - l + 1;
        int k = __lg(len);

        return min(
            st[k][l],
            st[k][r - (1 << k) + 1]);
    };

    /*
        求所有区间和的总和时需要：

        Σ pre[i]

        建 pre[] 本身的前缀和。

        只需要模 MOD。
    */

    vector<long long> sumPre(n + 2);

    for (int i = 0; i <= n; i++)
    {
        long long x = pre[i] % MOD;

        if (x < 0)
        {
            x += MOD;
        }

        sumPre[i + 1] =
            (sumPre[i] + x) % MOD;
    }

    auto rangeSumPre = [&](int l, int r) -> long long
    {
        long long res =
            sumPre[r + 1] - sumPre[l];

        res %= MOD;

        if (res < 0)
        {
            res += MOD;
        }

        return res;
    };

    /*
        查询串去重。

        相同字符串只插入 AC 自动机一次，
        最后映射回原查询。
    */

    AhoCorasick ac;

    unordered_map<string, int> mp;
    mp.reserve(q * 2 + 10);
    mp.max_load_factor(0.7);

    vector<int> queryId(q);

    // 对 unique query
    vector<int> len;

    int m = 0;

    for (int i = 0; i < q; i++)
    {
        string t;
        cin >> t;

        auto it = mp.find(t);

        if (it != mp.end())
        {
            queryId[i] = it->second;
        }
        else
        {
            int id = m++;

            mp[t] = id;
            queryId[i] = id;

            int u = ac.add(t);

            len.push_back((int)t.size());

            // 这个 Trie 节点是询问串 id 的终点
            ac.t[u].term = id;
        }
    }

    ac.work();

    /*
        last[id]：

        该询问串上一次出现的起点 p_{i-1}

        当前发现起点 p_i 时，
        处理：

        l ∈ [last + 1, p_i]
        r ∈ [p_i + len - 1, n]

        然后 last = p_i
    */

    vector<int> last(m, 0);

    vector<long long> ansMax(
        m,
        LLONG_MIN);

    vector<long long> ansSum(
        m,
        0);

    /*
        扫描 S。

        state 表示当前 AC 自动机状态。
    */

    int state = 1;

    for (int i = 1; i <= n; i++)
    {
        state = ac.next(state, S[i - 1]);

        /*
            当前 state 本身可能是询问串终点。

            另外沿 up 链还能找到所有
            同样在当前位置 i 结尾的询问串。
        */

        int u = state;

        while (u != 0)
        {
            int id = ac.t[u].term;

            if (id != -1)
            {
                int L = len[id];

                // 当前询问串出现起点
                int p = i - L + 1;

                // 当前出现结束位置
                int R0 = i;

                int prv = last[id];

                /*
                    这一块：

                    l ∈ [prv + 1, p]
                    r ∈ [R0, n]

                    x = l - 1：

                    x ∈ [prv, p - 1]
                */

                // ---------- 最大值 ----------

                long long bestRight =
                    sufMax[R0];

                long long bestLeft =
                    rangeMin(prv, p - 1);

                long long curMax =
                    bestRight - bestLeft;

                ansMax[id] =
                    max(ansMax[id], curMax);

                // ---------- 总和 ----------

                /*
                    ΣΣ(pre[r] - pre[x])

                    = cntL * Σpre[r]
                      - cntR * Σpre[x]
                */

                long long cntL =
                    p - prv;

                long long cntR =
                    n - R0 + 1;

                long long sumR =
                    rangeSumPre(R0, n);

                long long sumX =
                    rangeSumPre(prv, p - 1);

                long long contrib =
                    (cntL % MOD) * sumR % MOD;

                contrib -=
                    (cntR % MOD) * sumX % MOD;

                contrib %= MOD;

                if (contrib < 0)
                {
                    contrib += MOD;
                }

                ansSum[id] += contrib;
                ansSum[id] %= MOD;

                last[id] = p;
            }

            u = ac.t[u].up;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int id = queryId[i];

        cout
            << ansMax[id]
            << " "
            << ansSum[id]
            << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}