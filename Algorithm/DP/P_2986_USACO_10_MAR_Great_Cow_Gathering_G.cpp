#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        sum += c[i];
    }

    vector g(n + 1, vector<PII>());
    for (int i = 1; i < n; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
    }

    vector<int> sz(n + 1, 0);
    vector<int> tmp(n + 1);
    int ans = 0;
    auto pre = [&](auto &&self, int u, int fa) -> void
    {
        sz[u] = c[u];
        for (auto [v, val] : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            self(self, v, u);
            sz[u] += sz[v];
            ans += sz[v] * val;
        }
    };

    pre(pre, 1, 0);
    tmp[1] = ans;

    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        ans = min(ans, tmp[u]);
        for (auto [v, val] : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            tmp[v] = tmp[u] + val * (-sz[v] + (sum - sz[v]));
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    cout << ans << endl;
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