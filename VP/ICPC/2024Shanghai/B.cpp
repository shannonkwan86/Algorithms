#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    vector<int> sz(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sz[i] = g[i].size();
    }
    vector<int> vis(n + 1, 0);

    int idx = 1;

    vector<pair<int, int>> ans;

    auto visit = [&](int u)
    {
        if (vis[u])
            return;
        vis[u] = 1;
        for (auto v : g[u])
        {
            sz[v]--;
        }
    };
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        visit(u);
        // visit(u);

        if (sz[u] == 0 || idx > n)
        {
            return;
        }

        int v = p[idx++];

        if (!g[u].count(v))
        {
            ans.push_back({u, v});
        }

        self(self, v, u);  
        self(self, u, fa); 
        // while (sz[u] > 0 && idx <= n)
        // {
        //     int v = p[idx++];
        //     if (!g[u].count(v))
        //     {
        //         ans.push_back({u, v});
        //     }

        //     self(self, v, u);
        // }
    };
    for (int i = 1; i <= n; i++)
    {
        if (!vis[p[i]])
        {
            idx = i + 1;
            dfs(dfs, p[i], 0);
        }
    }
    dfs(dfs, p[1], 0);
    cout << ans.size() << endl;

    for (auto [x, y] : ans)
    {
        cout << x << " " << y << endl;
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