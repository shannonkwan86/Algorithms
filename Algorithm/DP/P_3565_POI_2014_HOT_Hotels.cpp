#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    vector<int> cnt(n + 1);
    vector<int> sum(n + 1);
    vector<int> pair(n + 1);

    for (int u = 1; u <= n; u++)
    {
        int maxDep = 0;

        for (int v : g[u])
        {
            auto dfs = [&](auto &&self, int cur, int fa, int dep) -> void
            {
                cnt[dep]++;
                maxDep = max(maxDep, dep);

                for (int to : g[cur])
                {
                    if (to == fa)
                        continue;
                    self(self, to, cur, dep + 1);
                }
            };

            dfs(dfs, v, u, 1);

            for (int d = 1; d <= maxDep; d++)
            {
                ans += cnt[d] * pair[d];
                pair[d] += cnt[d] * sum[d];
                sum[d] += cnt[d];
                cnt[d] = 0;
            }
        }

        for (int d = 1; d <= maxDep; d++)
        {
            sum[d] = 0;
            pair[d] = 0;
        }
    }

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
