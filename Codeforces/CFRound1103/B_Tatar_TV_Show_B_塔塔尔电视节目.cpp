#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // int bcnt = n / k + 1;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            mp[i % k]++;
        }
    }
    for (auto [x, y] : mp)
    {
        if (y % 2 != 0)
        {
            // cerr << "NK" << n << " " << k << endl;
            // cerr << x << " " << y << endl;
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}