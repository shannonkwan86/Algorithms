#include <bits/stdc++.h>
using namespace std;
#define int long long

struct BIT
{
    int n;
    vector<int> tree;
    BIT(int n1)
    {
        n = n1;
        tree.assign(n + 1, 0);
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void update(int idx, int num)
    {
        while (idx <= n)
        {
            tree[idx] = max(tree[idx], num);
            idx += lowbit(idx);
        }
    }
    int query(int idx)
    {
        int res = 0;
        while (idx > 0)
        {
            res = max(res, tree[idx]);
            idx -= lowbit(idx);
        }
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = {i + a[i], i};
    }
    sort(p.begin() + 1, p.end());

    BIT bit = BIT(n + 1);

    vector<int> dp(n + 1);
    int ans = 0;
    int ptr = 1;
    for (int j = 1; j <= n; j++)
    {
        while (ptr <= n && p[ptr].first < j)
        {
            int i = p[ptr].second;
            bit.update(i, dp[i]);
            ptr++;
        }
        int limit = j - a[j] - 1;
        if (limit >= 1)
            dp[j] = a[j] + bit.query(limit);
        else
            dp[j] = a[j];
        ans = max(ans, dp[j]);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}