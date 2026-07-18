#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    // cerr << sum << endl;
    if (sum == 0)
    {
        cout << "YES" << endl;
        return;
    }

    // bool ok = 1;

    // for (int i = 1; i < n; i++)
    // {
    //     if (a[i] == a[i + 1])
    //     {
    //         ok = false;
    //     }
    // }
    // if (sum != 0 && ok != 1)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }
    // else
    // {
    //     cout << "YES" << endl;
    //     return;
    // }
    if (sum % 4 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
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