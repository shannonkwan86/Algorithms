#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int m = a[n];
    vector<int> dp(m + 1);
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[a[i]] == 1)
        {
            continue;
        }
        ans++;

        for (int j = a[i]; j <= m; j++)
        {

            dp[j] = dp[j] || dp[j - a[i]];
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}