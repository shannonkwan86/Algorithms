#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long
const int INF = 4e18;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int pi;
        cin >> pi;
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int x;
            cin >> x;
            g[pi].push_back(x);
            g[x].push_back(pi);
        }
    }
    vector dp(n + 1, vector<int>(2, INF));
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        dp[u][1] = 1;
        dp[u][0] = 0;

        for (int v : g[u])
        {
            if (v != fa)
            {
                self(self, v, u);
                dp[u][1] += min(dp[v][0], dp[v][1]);
                dp[u][0] += dp[v][1];
            }
        }
    };
    dfs(dfs, 0, 0);
    cout << min(dp[0][0], dp[0][1]) << endl;
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