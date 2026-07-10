#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e8;
void solve()
{
    int m, n;
    cin >> m >> n;

    vector mp(m + 1, vector<int>(n + 1));
    vector<int> land(m + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
            land[i] = (land[i] << 1) | mp[i][j];
        }
    }

    vector<int> states;

    for (int s = 0; s < (1 << n); s++)
    {
        if ((s & (s << 1)) == 0)
        {
            states.push_back(s);
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));

    for (int s : states)
    {
        if ((s & land[1]) == s)
        {
            dp[1][s] = 1;
        }
    }

    for (int i = 2; i <= m; i++)
    {
        for (int cur : states)
        {
            if ((cur & land[i]) != cur)
                continue;

            for (int pre : states)
            {
                if ((pre & cur) != 0)
                    continue;

                dp[i][cur] = (dp[i][cur] + dp[i - 1][pre]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int s : states)
    {
        ans = (ans + dp[m][s]) % MOD;
    }

    cout << ans << '\n';
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