#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    auto check = [&](int l, int r, int len) -> bool
    {
        for (int i = l + len; i <= r; i++)
        {
            if (s[i] != s[i - len])
            {
                return false;
            }
        }
        return true;
    };

    for (int leng = 1; leng <= n; leng++)
    {
        for (int l = 1; l + leng - 1 <= n; l++)
        {
            int r = l + leng - 1;
            dp[l][r] = leng;
            for (int k = l; k < r; k++)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
            for (int len = 1; len <= leng; len++)
            {
                if (leng % len != 0)
                {
                    continue;
                }
                else
                {
                    if (check(l, r, len))
                    {
                        dp[l][r] = min((unsigned long long) dp[l][r], dp[l][l + len - 1] + 2 + to_string(leng / len).size());
                    }
                }
            }
        }
    }
    cout << dp[1][n] << endl;
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