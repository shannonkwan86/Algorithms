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
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    vector<int> cnt(n + 1);
    vector<double> f(n + 1);
    auto dfs1 = [&](auto &&self, int u, int fa) -> void
    {
        if (g[u].size() == 1)
        {
            cnt[u] = 1;
            f[u] = val[u];
        }

        for (int v : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            self(self, v, u);
            cnt[u] += cnt[v];
            f[u] += f[v] + cnt[v] * val[u];
        }
    };
    dfs1(dfs1, 1, 0);

    int leaf = cnt[1];
    vector<double> sum(n + 1);
    sum[1] = f[1];
    double ans = -1e100;

    auto dfs2 = [&](auto &&self, int u, int fa) -> void
    {
        if (g[u].size() == 1)
        {
            ans = max(ans, (sum[u] - val[u]) / (leaf - 1));
        }
        else
        {
            ans = max(ans, sum[u] / leaf);
        }

        for (int v : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            sum[v] = sum[u] - cnt[v] * val[u] + (leaf - cnt[v]) * val[v];
            self(self, v, u);
        }
    };
    dfs2(dfs2, 1, 0);

    cout << fixed << setprecision(4) << ans << endl;
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