#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<vector<int>> f(n + 1, vector<int>(n + 1));
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    auto check = [&](int l, int r) -> bool
    {
        int mid = (l + r) / 2;
        int len = (r - l + 1);
        if (len % 2 != 0)
        {
            return false;
        }
        for (int i = mid + 1; i <= r; i++)
        {
            if (s[i - len / 2] != s[i])
            {
                return false;
            }
        }
        return true;
    };

    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            f[l][r] = g[l][r] = len;
            for (int k = l; k < r; k++)
            {
                f[l][r] = min(f[l][r], min(f[l][k], g[l][k]) + 1 + min(f[k + 1][r], g[k + 1][r]));
            }

            for (int k = l; k < r; k++)
            {
                g[l][r] = min(g[l][r], g[l][k] + (r - k));
            }

            if (check(l, r))
            {
                int mid = (l + r) / 2;
                g[l][r] = min(g[l][r], g[l][mid] + 1);
            }
        }
    }
    cout << min(f[1][n], g[1][n]) << endl;
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