#include <bits/stdc++.h>
using namespace std;
#define int long long

int hb(int x)
{
    int res = 1;
    while ((res << 1) <= x)
        res <<= 1;
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);

    sort(id.begin(), id.end(), [&](int x, int y)
         {
             if (a[x] != a[y])
                 return a[x] < a[y];
             return x < y; });

    vector<int> to(n);

    for (int i = 0; i < n; i++)
    {
        to[id[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i ^ to[i]) != 0)
            ans = max(ans, hb(i ^ to[i]));
    }
    cout << ans << endl;
    // sort()
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