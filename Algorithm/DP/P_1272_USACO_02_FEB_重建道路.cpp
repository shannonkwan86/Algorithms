#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n, p;
    cin >> n >> p;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 4e18));
    vector<int> sz(n + 1);

    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        dp[u][1] = 0;
        sz[u] = 1;
        // auto tep = dp;

        for (int v : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            self(self, v, u);
            // for (int )
            //     tep[u][]
            vector<int> tep(p + 1, 4e18);
            for (int i = min(p, sz[u]); i >= 1; i--)
            {
                // tep[u][i] = min(dp[u][i] + 1, tep[u][i]);
                tep[i] = min(dp[u][i] + 1, tep[i]);
                for (int t = min(p - i, sz[v]); t >= 1; t--)
                {
                    tep[i + t] = min(tep[i + t], dp[v][t] + dp[u][i]);
                }
            }
            sz[u] += sz[v];
            dp[u] = tep;
        }
    };
    dfs(dfs, 1, 0);
    int ans = dp[1][p];
    for (int i = 2; i <= n; i++)
    {
        ans = min(ans, dp[i][p] + 1);
    }
    cout << ans << endl;
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