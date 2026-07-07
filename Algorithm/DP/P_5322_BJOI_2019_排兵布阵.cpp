#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int s, n, m;
    cin >> s >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(s));

    for (int i = 0; i < s; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[j][i];
        }
    }
    vector<vector<pair<int, int>>> options(n + 1);
    for (int i = 1; i <= n; i++)
    {
        // sort(g[i].begin(), g[i].end());
        vector<int> tep;
        for (int x : g[i])
        {
            tep.push_back(2 * x + 1);
        }
        sort(tep.begin(), tep.end());
        options[i].push_back({0, 0});
        for (int j = 0; j < s; j++)
        {
            if (j == s - 1 or tep[j] != tep[j + 1])
            {
                options[i].push_back({tep[j], (j + 1) * i});
            }
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (auto [x, y] : options[i])
            {
                // dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + y);
                if (j >= x)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + y);
                }
            }
        }
    }

    int ans = 0;
    for (int j = m; j >= 0; j--)
    {
        ans = max(ans, dp[n][j]);
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