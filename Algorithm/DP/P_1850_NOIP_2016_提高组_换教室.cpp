#include <bits/stdc++.h>
using namespace std;
// #define int long long

const double INF = 1e9;

void solve()
{
    int n, m, v, e;
    cin >> n >> m >> v >> e;
    vector<int> c(n + 1);
    vector<int> d(n + 1);
    vector<double> k(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }

    vector<vector<int>> dis(v + 1, vector<int>(v + 1, INF));

    for (int x = 1; x <= v; x++)
    {
        for (int y = 1; y <= v; y++)
        {
            dis[x][y] = INF;
        }
        dis[x][x] = 0;
    }

    for (int i = 1; i <= e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = min(dis[a][b], w);
        dis[b][a] = min(dis[b][a], w);
    }

    for (int k = 1; k <= v; k++)
    {
        for (int x = 1; x <= v; x++)
        {
            for (int y = 1; y <= v; y++)
            {
                dis[x][y] = min(dis[x][y], dis[x][k] + dis[k][y]);
            }
        }
    }

    vector<vector<array<double, 2>>> f(n + 1, vector<array<double, 2>>(m + 1, {INF, INF}));

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            f[1][0][0] = 0;
            if (m >= 1)
                f[1][1][1] = 0;
            continue;
        }
        for (int j = 0; j <= min(i, m); j++)
        {
            f[i][j][0] = min(f[i - 1][j][1] + k[i - 1] * dis[d[i - 1]][c[i]] + (1 - k[i - 1]) * dis[c[i - 1]][c[i]], f[i - 1][j][0] + dis[c[i - 1]][c[i]]);

            if (j > 0)
            {

                f[i][j][1] = min(f[i - 1][j - 1][0] + k[i] * dis[c[i - 1]][d[i]] + (1 - k[i]) * dis[c[i - 1]][c[i]], f[i - 1][j - 1][1] + k[i - 1] * k[i] * dis[d[i - 1]][d[i]] + k[i - 1] * (1 - k[i]) * dis[d[i - 1]][c[i]] + (1 - k[i - 1]) * k[i] * dis[c[i - 1]][d[i]] + (1 - k[i - 1]) * (1 - k[i]) * dis[c[i - 1]][c[i]]);
            }
        }
    }
    double ans = INF;
    for (int j = 0; j <= m; j++)
    {
        ans = min(ans, f[n][j][0]);
        ans = min(ans, f[n][j][1]);
    }
    cout << fixed << setprecision(2) << ans << endl;
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