#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<string> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i] = " " + b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(t + 1));
    vector<vector<int>> best(n + 1, vector<int>(m + 1));

    for (int row = 1; row <= n; row++)
    {
        vector<vector<int>> g(m + 1, vector<int>(m + 1));
        vector<int> pre(m + 1);
        for (int i = 1; i <= m; i++)
        {
            pre[i] = pre[i - 1];
            if (b[row][i] == '1')
                pre[i]++;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int k = 1; k <= i; k++)
            {
                for (int j = 0; j < i; j++)
                {
                    int one = pre[i] - pre[j];
                    int zero = i - j - one;
                    g[i][k] = max(g[i][k], g[j][k - 1] + max(one, zero));
                }
            }
        }
        for (int k = 0; k <= m; k++)
        {
            best[row][k] = g[m][k];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int tt = 0; tt <= t; tt++)
        {
            for (int k = 0; k <= min(m, tt); k++)
            {
                dp[i][tt] = max(dp[i][tt], dp[i - 1][tt - k] + best[i][k]);
            }
        }
    }

    int ans = 0;
    for (int tt = 0; tt <= t; tt++)
    {
        ans = max(ans, dp[n][tt]);
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