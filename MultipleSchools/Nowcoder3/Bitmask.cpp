#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int x)
{
    int cnt = 0;
    bool fg = 0;

    while (x)
    {
        if (x % 2 == 1)
        {
            fg = 1;
        }
        else if (fg == 1)
        {
            cnt++;
            fg = 0;
        }
        x /= 2;
    }
    if (fg == 1)
    {
        cnt++;
        fg = 0;
    }
    return cnt;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += f(a[i]);
    }
    cout << ans << endl;

    
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int type, x;
        cin >> type >> x;
    }
    
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