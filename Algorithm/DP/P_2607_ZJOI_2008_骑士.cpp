#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> p(n), to(n);
    for (int i = 0; i < n; i++)
    {
        int val, tar;
        cin >> val >> tar;
        tar--;
        p[i] = val;
        to[i] = tar;
        g[i].push_back(tar);
        g[tar].push_back(i);
    }

    queue<int> q;
    vector<int> deg(n);
    vector<bool> inCycle(n, true);

    for (int i = 0; i < n; i++)
    {
        deg[i] = g[i].size();
        if (deg[i] == 1)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        inCycle[u] = false;
        q.pop();
        for (int v : g[u])
        {
            if (!inCycle[v])
                continue;

            deg[v]--;

            if (deg[v] == 1)
            {
                q.push(v);
            }
        }
    }

    const int NEG = -(1LL << 60);
    vector<array<int, 2>> dp(n, {NEG, NEG});

    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        dp[u][0] = 0;
        dp[u][1] = p[u];
        for (int v : g[u])
        {
            if (v == fa)
                continue;
            if (inCycle[v])
                continue;
            self(self, v, u);
            dp[u][0] = dp[u][0] + max(dp[v][1], dp[v][0]);
            dp[u][1] = dp[u][1] + dp[v][0];
        }
    };

    vector<bool> visCycle(n, false);
    int ans = 0;

    for (int start = 0; start < n; start++)
    {
        if (!inCycle[start] || visCycle[start])
            continue;

        vector<int> cyc;
        int cur = start;

        while (!visCycle[cur])
        {
            visCycle[cur] = true;
            cyc.push_back(cur);
            cur = to[cur];
        }

        for (int u : cyc)
        {
            dfs(dfs, u, u);
        }

        int m = cyc.size();
        vector<vector<vector<int>>> f(m, vector<vector<int>>(2, vector<int>(2, NEG)));
        f[0][0][0] = dp[cyc[0]][0];
        f[0][1][1] = dp[cyc[0]][1];
        for (int i = 1; i < m; i++)
        {
            f[i][0][0] = max(f[i - 1][1][0], f[i - 1][0][0]) + dp[cyc[i]][0];
            f[i][1][0] = f[i - 1][0][0] + dp[cyc[i]][1];
            f[i][0][1] = max(f[i - 1][1][1], f[i - 1][0][1]) + dp[cyc[i]][0];
            f[i][1][1] = f[i - 1][0][1] + dp[cyc[i]][1];
        }
        ans += max(
            {f[m - 1][0][0],
             f[m - 1][1][0],
             f[m - 1][0][1]});
    }

    cout << ans << endl;
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
