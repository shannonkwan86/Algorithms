#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 4e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<array<int, 2>> dp(n + 2, {0, 0});
    // dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        // cerr<<a[i-1]<<endl;
        dp[i][0] = min(dp[i - 1][0] + a[i - 1], dp[i - 1][1]);
        dp[i][1] = min(dp[i - 1][1] + a[i + 1], dp[i - 1][0] + max(a[i + 1], a[i - 1]));
        // cerr << dp[i][0] << " " << dp[i][1] << endl;
    }

    cout << dp[n][0] << endl;
    // cerr << endl;
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