#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        a[i] = a[i - n];
    }
    vector<vector<int>> mn(2 * n + 1, vector<int>(2 * n + 1, 4e18));
    vector<vector<int>> mx(2 * n + 1, vector<int>(2 * n + 1, -4e18));

    vector<int> sum(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++)
    {
        sum[i] = sum[i - 1];
        sum[i] += a[i];
        // cerr << sum[i] << " ";
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        mn[i][i] = 0;
        mx[i][i] = 0;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l <= 2 * n - len + 1; l++)
        {
            int r = l + len - 1;
            int s = sum[r] - sum[l - 1];
            for (int k = l; k < r; k++)
            {
                mn[l][r] = min(mn[l][r], mn[l][k] + mn[k + 1][r] + s);
                mx[l][r] = max(mx[l][r], mx[l][k] + mx[k + 1][r] + s);
            }
        }
    }

    int ansmin = 4e18;
    int ansmax = -4e18;
    for (int i = 1; i <= n; i++)
    {
        ansmin = min(ansmin, mn[i][i + n - 1]);
        ansmax = max(ansmax, mx[i][i + n - 1]);
    }
    cout << ansmin << endl
         << ansmax << endl;
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