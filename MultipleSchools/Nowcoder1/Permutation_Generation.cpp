#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n );
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (x == a[k])
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        return;
    }
    if (x < a[k])
    {
        x += n;
    }
    int dif = x - a[k];
    for (int i = 0; i < n; i++)
    {
        a[i] = (a[i] + dif) % n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}