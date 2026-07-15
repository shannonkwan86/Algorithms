#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
        {
            cnt++;
        }
        if (s[i] == '*')
        {
            ans = max(ans, (cnt + 1) / 2);
            cnt = 0;
        }
    }
    ans = max(ans, (cnt + 1) / 2);
    cnt = 0;
    cout << ans << endl;
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