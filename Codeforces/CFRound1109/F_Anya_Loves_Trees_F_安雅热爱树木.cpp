#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Info
{
    int mx;
    int mn;
    int cnt;
    int ok;
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int pi;
        cin >> pi;
        g[pi].push_back(i);
    }

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<Info> p(n + 1);

    auto dfs = [&](auto &&self, int u) -> void
    {
        p[u].mn = LLONG_MAX;
        p[u].mx = LLONG_MIN;
        p[u].cnt = 0;
        p[u].ok = 1;

        if (g[u].size() == 0)
        {
            p[u].cnt = 1;
            p[u].mx = a[u];
            p[u].mn = a[u];
            p[u].ok = 1;
            return;
        }
        for (int v : g[u])
        {

            self(self, v);
            p[u].mn = min(p[u].mn, p[v].mn);
            p[u].mx = max(p[u].mx, p[v].mx);
            p[u].cnt += p[v].cnt;
            if (p[v].ok == 0)
            {
                p[u].ok = 0;
                return;
            }
        }
        if (!p[u].ok)
        {
            return;
        }
        int gap = 0;

        int m = g[u].size();

        for (int i = 0; i < m; i++)
        {
            int j = (i + 1) % m;

            int x = g[u][i];
            int y = g[u][j];

            if (p[y].mn != p[x].mx + 1)
            {
                gap++;
            }
        }
        if (gap > 1)
        {
            p[u].ok = 0;
        }
    };
    dfs(dfs, 1);
    cout << (p[1].ok ? "YES" : "NO") << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}