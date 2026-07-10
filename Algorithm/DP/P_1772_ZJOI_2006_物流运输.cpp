#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 4e18;
void solve()
{
    int n, m, k, e;
    cin >> n >> m >> k >> e;
    vector<vector<pair<int, int>>> edge(m + 1);
    for (int i = 1; i <= e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    int d;
    cin >> d;
    vector<vector<pair<int, int>>> dock(m + 1);
    for (int i = 1; i <= d; i++)
    {
        int p, a, b;
        cin >> p >> a >> b;
        dock[p].push_back({a, b});
    }

    auto dij = [&](int l, int r) -> int
    {
        vector<bool> bad(m + 1, false);
        vector<int> dis(m + 1, INF);
        vector<bool> vis(m + 1, false);
        for (int p = 1; p <= m; p++)
        {
            for (auto [a, b] : dock[p])
            {
                if (!(b < l || a > r))
                {
                    bad[p] = true;
                }
            }
        }

        dis[1] = 0;

        for (int t = 1; t <= m; t++)
        {
            int u = -1;

            for (int i = 1; i <= m; i++)
            {
                if (!vis[i] && !bad[i] && (u == -1 || dis[i] < dis[u]))
                {
                    u = i;
                }
            }

            if (u == -1)
                break;
            vis[u] = true;

            for (auto [v, w] : edge[u])
            {
                if (bad[v])
                    continue;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                }
            }
        }

        return dis[m];
    };

    vector<vector<int>> cost(n + 1, vector<int>(n + 1));
    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            cost[l][r] = dij(l, r);
        }
    }

    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (dp[j - 1] == INF || cost[j][i] == INF)
                continue;
            dp[i] = min(dp[i],
                        dp[j - 1] + cost[j][i] * (i - j + 1) + (j == 1 ? 0 : k));
        }
    }
    cout << dp[n] << endl;
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