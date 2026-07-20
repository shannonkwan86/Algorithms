#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 6e5;

int a[N];
int fa[N];
int tag[N]; // 可以留着，不用了
int mx[N];
int sz[N];
int val[N];
bool act[N];

int find(int x)
{
    if (fa[x] == x)
        return x;

    int p = fa[x];
    fa[x] = find(p);

    // mx[x]：x 到原父亲 p 的最大门槛
    // mx[p]：p 到根的最大门槛
    mx[x] = max(tag[x], mx[p]);
    tag[x] = mx[x];
    return fa[x];
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    auto merge = [&](int x, int y) -> void
    {
        int rx = find(x);
        int ry = find(y);
        fa[rx] = ry;
    };

    auto getId = [&](int x, int y) -> int
    {
        return (x - 1) * m + (y - 1);
    };

    int l = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int id = i * m + j;
            fa[id] = id;
        }
    }

    for (int i = 1; i <= q; i++)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int x1, y1, v;
            cin >> x1 >> y1 >> v;

            int x = x1 ^ l;
            int y = y1 ^ l;
            int id = getId(x, y);

            sz[id] = 1;
            val[id] = v;
            act[id] = 1;
            mx[id] = 0;

            vector<int> cnd;

            if (x > 1)
            {
                cnd.push_back(getId(x - 1, y));
            }
            if (x < n)
            {
                cnd.push_back(getId(x + 1, y));
            }
            if (y > 1)
            {
                cnd.push_back(getId(x, y - 1));
            }
            if (y < m)
            {
                cnd.push_back(getId(x, y + 1));
            }

            set<int> st;

            for (auto x : cnd)
            {
                if (act[x] == 1)
                {
                    st.insert(find(x));
                }
            }

            for (auto x : st)
            {
                sz[id] += sz[x];
                tag[x] = v - sz[x] + 1;
                fa[x] = id;
            }

            long long ans = sz[id] - 1;
            cout << ans << '\n';
            l = ans;
        }
        else
        {
            int x1, y1;
            cin >> x1 >> y1;

            int x = x1 ^ l;
            int y = y1 ^ l;
            int id = getId(x, y);

            find(id);

            long long ans = max(0LL, mx[id] - val[id]);
            cout << ans << '\n';
            l = ans;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}