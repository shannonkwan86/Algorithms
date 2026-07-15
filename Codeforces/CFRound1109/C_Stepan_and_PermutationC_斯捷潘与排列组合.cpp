#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1);
    vector<int> p(n + 1);
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[a[i]] = i;
        if ((p[a[i]] - a[i]) % gcd(x, y))
        {
            ok = false;
        }
    }
    if (ok)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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