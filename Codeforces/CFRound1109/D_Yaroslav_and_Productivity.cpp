#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 4e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // vector<int> b(m + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= m; i++)
    {
        // cin >> b[i];
        int x;
        cin >> x;
        p[x]++;
    }

    vector<array<int, 2>> f(n + 2);
    f[n + 1][0] = 0;
    f[n + 1][1] = -INF;
    for (int i = n; i >= 1; i--)
    {
        if (p[i] == 0)
        {

            f[i][0] = a[i] + f[i + 1][0];
            f[i][1] = -a[i] + f[i + 1][1];
        }
        else
        {
            f[i][0] = a[i] + max(f[i + 1][0], f[i + 1][1]);
            f[i][1] = -a[i] + max(f[i + 1][0], f[i + 1][1]);
        }
    }
    cout << max(f[1][0], f[1][1]) << endl;
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