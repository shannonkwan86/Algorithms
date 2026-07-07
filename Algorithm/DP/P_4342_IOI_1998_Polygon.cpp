#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<char> c(2 * n + 1);
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> a[i];
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        c[i] = c[i - n];
        a[i] = a[i - n];
    }

    const int INF = 4e18;

    vector<vector<int>> mx(2 * n + 1, vector<int>(2 * n + 1, -INF));
    vector<vector<int>> mn(2 * n + 1, vector<int>(2 * n + 1, INF));
    for (int i = 1; i <= 2 * n; i++)
    {
        mx[i][i] = a[i];
        mn[i][i] = a[i];
    }

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= 2 * n; l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
            {
                if (c[k + 1] == 't')
                {
                    mn[l][r] = min(mn[l][r], mn[l][k] + mn[k + 1][r]);
                    mx[l][r] = max(mx[l][k] + mx[k + 1][r], mx[l][r]);
                }
                else
                {
                    mx[l][r] = max({mx[l][r], mx[l][k] * mx[k + 1][r], mx[l][k] * mn[k + 1][r], mn[l][k] * mx[k + 1][r], mn[l][k] * mn[k + 1][r]});
                    mn[l][r] = min({mn[l][r], mx[l][k] * mx[k + 1][r], mx[l][k] * mn[k + 1][r], mn[l][k] * mx[k + 1][r], mn[l][k] * mn[k + 1][r]});
                }
            }
        }
    }

    int mxrating = -4e18;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (mx[i][i + n - 1] > mxrating)
        {
            mxrating = mx[i][i + n - 1];
            ans.clear();
            ans.push_back(i);
        }
        else if (mx[i][i + n - 1] == mxrating)
        {
            ans.push_back(i);
        }
    }
    cout << mxrating << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
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