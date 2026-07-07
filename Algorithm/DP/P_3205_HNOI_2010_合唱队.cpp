#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long
const int MOD = 19650827;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<array<int, 2>>> dp(n + 1, vector<array<int, 2>>(n + 1, {0, 0}));

    for (int i = 1; i <= n; i++)
    {
        dp[i][i][0] = 1;
        dp[i][i][1] = 0;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if (a[l + 1] > a[l])
                dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][0]) % MOD;

            if (a[r] > a[l])
                dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][1]) % MOD;

            if (a[l] < a[r])
                dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][0]) % MOD;

            if (a[r - 1] < a[r])
                dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][1]) % MOD;
        }
    }

    int ans = (dp[1][n][0] + dp[1][n][1]) % MOD;
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