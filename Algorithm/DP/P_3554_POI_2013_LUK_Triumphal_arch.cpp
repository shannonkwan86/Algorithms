#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto check = [&](int k) -> bool
    {
        vector<int> f(n + 1, 0);

        auto dfs = [&](auto &&self, int u, int fa) -> void
        {
            int sum = 0;
            for (auto v : g[u])
            {
                if (v == fa)
                    continue;
                self(self, v, u);
                sum += f[v] + 1;
            }
            f[u] = max(0LL, sum - k);
        };

        dfs(dfs, 1, 0);
        return f[1] == 0;
    };

    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << '\n';
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