#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long
const int INF = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    vector<int> caps = b;
    sort(caps.rbegin(), caps.rend());

    int k = 0, capSum = 0;
    while (capSum < m)
    {
        capSum += caps[k];
        k++;
    }

    vector dp(k + 1, vector<int>(10001, -INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = k - 1; j >= 0; j--)
        {
            for (int c = 0; c + b[i] <= 10000; c++)
            {
                if (dp[j][c] == -INF)
                {
                    continue;
                }
                // f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j - b[i]][k] + a[i]);
                dp[j + 1][c + b[i]] = max(dp[j + 1][c + b[i]], dp[j][c] + a[i]);
            }
        }
    }

    int keep = 0;
    for (int c = m; c <= 10000; c++)
    {
        keep = max(keep, dp[k][c]);
    }

    cout << k << ' ' << m - keep << '\n';
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