#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
// #define int long long
// const int INF = 2e9;

void solve()
{
    int n, b;
    cin >> n >> b;
    int INF = b + 1;
    vector<int> c(n + 1);
    vector<int> d(n + 1);
    vector<int> sz(n + 1);

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> d[i];
        if (i >= 2)
        {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
    }
    vector<vector<array<int, 2>>> dp(
        n + 1,
        vector<array<int, 2>>(n + 1, {INF, INF}));
    // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, INF)));
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        sz[u] = 1;
        dp[u][0][0] = 0;
        dp[u][1][0] = c[u];
        dp[u][1][1] = c[u] - d[u];

        for (int v : g[u])
        {
            self(self, v, u);

            // int low = (u == 0 ? 0 : 1);

            for (int j = sz[u]; j >= 0; j--)
            {
                for (int k = 1; k <= sz[v] && j + k <= n; k++)
                {
                    dp[u][j + k][0] = min(dp[u][j + k][0], dp[u][j][0] + dp[v][k][0]);
                    dp[u][j + k][1] = min(dp[u][j + k][1], dp[u][j][1] + min(dp[v][k][1], dp[v][k][0]));
                    // dp[u][j + k] = max(dp[u][j + k], dp[u][j] + dp[x][k]);
                }
            }

            sz[u] += sz[v];
        }
    };
    dfs(dfs, 1, 0);

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (min(dp[1][i][0], dp[1][i][1]) <= b)
        {
            ans = i;
        }
    }

    cout << ans << '\n';
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