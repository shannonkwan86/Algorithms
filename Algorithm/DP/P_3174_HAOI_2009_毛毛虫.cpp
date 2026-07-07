#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dp(n + 1);
    vector<int> cnt(n + 1);
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    int ans = -4e18;
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        cnt[u] = g[u].size();
        dp[u] = cnt[u];
        int mx1 = 0;
        int mx2 = 0;
        for (int v : g[u])
        {
            if (v != fa)
            {
                self(self, v, u);

                if (dp[v] >= mx1)
                {
                    mx2 = mx1;
                    mx1 = dp[v];
                }
                else if (dp[v] > mx2)
                {
                    mx2 = dp[v];
                }
            }
        }
        int val = cnt[u] - 1;

        dp[u] = val + mx1;
        ans = max(ans, val + mx1 + mx2);
        // ans = max(ans, dp[u]);
    };
    dfs(dfs, 1, 0);
    // ans = max(ans, dp[1]);
    cout << ans + 2 << endl;
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