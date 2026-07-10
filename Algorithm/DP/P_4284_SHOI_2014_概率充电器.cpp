#include <bits/stdc++.h>
using namespace std;
// #define int long long

void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, double>>> edge(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        double p;
        cin >> a >> b >> p;
        edge[a].push_back({b, p / 100.0});
        edge[b].push_back({a, p / 100.0});
    }
    vector<double> q(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
        q[i] /= 100.0;
    }

    vector<double> f(n + 1);
    auto dfs1 = [&](auto &&self, int u, int fa) -> void
    {
        f[u] = 1 - q[u];
        for (auto [x, y] : edge[u])
        {
            if (x == fa)
            {
                continue;
            }
            else
            {
                self(self, x, u);
                f[u] *= (1 - y * (1 - f[x]));
            }
        }
    };

    dfs1(dfs1, 1, 0);

    vector<double> g(n + 1);

    auto dfs2 = [&](auto &&self, int u, int fa) -> void
    {
        vector<int> child;
        vector<double> pval;
        vector<double> contrib;

        for (auto [x, y] : edge[u])
        {
            if (x == fa)
                continue;

            child.push_back(x);
            pval.push_back(y);
            contrib.push_back(1 - y * (1 - f[x]));
        }

        int m = contrib.size();
        vector<double> pre(m + 1, 1), suf(m + 1, 1);

        for (int i = 0; i < m; i++)
        {
            pre[i + 1] = pre[i] * contrib[i];
        }

        for (int i = m - 1; i >= 0; i--)
        {
            suf[i] = suf[i + 1] * contrib[i];
        }

        for (int i = 0; i < m; i++)
        {
            int v = child[i];
            double p = pval[i];

            double prod_except = pre[i] * suf[i + 1];

            double H = (1 - q[u]) * g[u] * prod_except;

            g[v] = 1 - p * (1 - H);

            self(self, v, u);
        }
    };

    g[1] = 1;
    dfs2(dfs2, 1, 0);

    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += 1 - f[i] * g[i];
    }
    cout << fixed << setprecision(6) << ans << '\n';
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