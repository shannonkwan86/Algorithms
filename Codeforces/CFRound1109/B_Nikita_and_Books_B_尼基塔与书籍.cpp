#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        int ai;
        cin >> ai;
        sum += ai;
        if (sum < (i + 1) * i / 2)
        {
            ok = false;
            // break;
        }
    }
    // cerr << n << "  " << sum << endl;
    // cout << sum << " " << (n + 1) * n / 2 << endl;

    // cout << sum << endl;
    if (ok)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    // cout << endl;
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