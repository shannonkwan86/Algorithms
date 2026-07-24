#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int u, int fa, vector<vector<int>> &g, vector<int> &dep,
         vector<vector<int>> &f, vector<int> &lg)
{
    f[0][u] = fa ? fa : u;
    dep[u] = fa ? dep[fa] + 1 : 1;

    for (int k = 1; k <= lg[dep[u]]; k++)
        f[k][u] = f[k - 1][f[k - 1][u]];

    for (int v : g[u])
    {
        if (v != fa)
            dfs(v, u, g, dep, f, lg);
    }
}

int lca(int x, int y, vector<int> &dep, vector<vector<int>> &f,
        vector<int> &lg)
{
    if (dep[x] > dep[y])
        swap(x, y);
    while (dep[x] < dep[y])
        y = f[lg[dep[y] - dep[x]]][y];
    if (x == y)
        return x;
    for (int k = lg[dep[x]]; k >= 0; k--)
    {
        if (f[k][x] != f[k][y])
        {
            x = f[k][x];
            y = f[k][y];
        }
    }
    return f[0][x];
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> lg(n + 1), dep(n + 1);
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    vector<vector<int>> f(30, vector<int>(n + 1));
    dfs(1, 0, g, dep, f, lg);

    vector<int> mu(n + 1), pri;
    vector<bool> vis(n + 1);
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pri.push_back(i);
            mu[i] = -1;
        }
        for (int p : pri)
        {
            if (i * p > n)
                break;
            vis[i * p] = true;
            if (i % p == 0)
            {
                mu[i * p] = 0;
                break;
            }
            mu[i * p] = -mu[i];
        }
    }

    int ans = 0;
    for (int d = 1; d <= n; d++)
    {
        for (int x = d; x <= n; x += d)
        {
            for (int y = x + d; y <= n; y += d)
            {
                int u = lca(x, y, dep, f, lg);
                if (d % u == 0)
                    ans += mu[d / u];
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
