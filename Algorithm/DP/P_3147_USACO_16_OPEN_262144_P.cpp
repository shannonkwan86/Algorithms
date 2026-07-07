#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(60, vector<int>(n + 2));
    for (int i = 1; i <= n; i++)
    {
        dp[a[i]][i] = i;
    }
    for (int i = 1; i <= 59; i++)
    {
        for (int l = 1; l <= n; l++)
        {
            int mid = dp[i - 1][l];
            if (mid && mid + 1 <= n)
                dp[i][l] = dp[i - 1][dp[i - 1][l] + 1];
        }
    }

    for (int i = 59; i >= 1; i--)
    {
        for (int l = 1; l <= n; l++)
        {
            if (dp[i][l] >= 1 && dp[i][l] <= n)
            {
                cout << i << endl;
                return;
            }
        }
    }
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