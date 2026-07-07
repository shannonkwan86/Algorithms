#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= n - m; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a, c;
            cin >> a >> c;
            g[a].push_back({i, c});
            g[i].push_back({a, c});
        }
    }

    vector<int> pay(n + 1);
    for (int i = n - m + 1; i <= n; i++)
    {
        cin >> pay[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -4e18));

    vector<int> sz(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        dp[u][0] = 0;
        if (u >= n - m + 1)
        {
            // dp[u][0] = 0;
            dp[u][1] = pay[u];
            sz[u] = 1;
        }
        for (auto [v, cost] : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            self(self, v, u);

            for (int j = sz[u]; j >= 0; j--)
            {
                for (int t = 1; t <= sz[v]; t++)
                {
                    {
                        dp[u][j + t] = max(dp[u][j + t], dp[u][j] + dp[v][t] - cost);
                    }
                }
            }
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 1, 0);

    for (int k = m; k >= 0; k--)
    {
        if (dp[1][k] >= 0)
        {
            cout << k << endl;
            break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}