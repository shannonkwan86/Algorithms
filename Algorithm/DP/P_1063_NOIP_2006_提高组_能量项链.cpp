#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> num(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        num[i] = num[i - n];
    }
    int ans = 0;
    vector dp(2 * n + 1, vector<int>(2 * n + 1, 0));

    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= 2 * n - 1; l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
            {
                dp[l][r] = max(dp[l][r],
                               dp[l][k] + dp[k + 1][r] + num[l] * num[k + 1] * num[r + 1]);
            }
        }
    }

    // int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i][i + n - 1]);
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