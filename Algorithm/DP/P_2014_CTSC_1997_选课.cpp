#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> s(n + 1);
    vector<int> sz(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -0x3f));
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k >> s[i];
        g[k].push_back(i);
    }
    

    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        sz[u] = 1;

        if (u == 0)
        {
            dp[u][0] = 0;
        }
        else
        {
            dp[u][1] = s[u];
        }

        for (auto x : g[u])
        {
            self(self, x, u);

            int low = (u == 0 ? 0 : 1);

            for (int j = min(sz[u], m); j >= low; j--)
            {
                for (int k = 1; k <= sz[x] && j + k <= m; k++)
                {
                    dp[u][j + k] = max(dp[u][j + k], dp[u][j] + dp[x][k]);
                }
            }

            sz[u] += sz[x];
        }
    };
    dfs(dfs, 0, 0);

    cout << dp[0][m] << '\n';
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