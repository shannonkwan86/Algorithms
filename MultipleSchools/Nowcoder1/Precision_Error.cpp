#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int m = 2 * n;
    cout << m << endl;
    for (int i = 0; i < n; i++)
    {
        double x = 0.011 * (i % 10);
        double y = 0.011 * (i / 10);
        cout << fixed << setprecision(9) << x << " " << y << " " << 0 << endl;
    }
    for (int i = 0; i < n; i++)
    {
        double x = 0.011 * (i % 10);
        double y = 0.011 * (i / 10);
        cout << fixed << setprecision(9) << x << " " << y << " " << 1 << endl;
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