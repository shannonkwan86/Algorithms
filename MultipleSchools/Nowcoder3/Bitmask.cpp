#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    // int ans = 0;

    vector<array<array<int, 2>, 2>> b(31);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // ans += f(a[i]);
        for (int j = 29; j >= 0; j--)
        {

            int cur = (a[i] >> j) & 1;
            int nxt = (a[i] >> (j + 1)) & 1;
            b[j + 1][nxt][cur]++;
        }
    }

    // cout << ans << endl;

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int type, x;
        cin >> type >> x;
        for (int j = 1; j <= 30; j++)
        {
            array<array<int, 2>, 2> tmp{};
            int high = (x >> j) & 1;
            int low = (x >> (j - 1)) & 1;

            if (type == 1)
            {
                for (int p = 0; p <= 1; p++)
                {
                    for (int q = 0; q <= 1; q++)
                    {
                        tmp[p & high][q & low] += b[j][p][q];
                    }
                }
            }
            if (type == 2)
            {
                for (int p = 0; p <= 1; p++)
                {
                    for (int q = 0; q <= 1; q++)
                    {
                        tmp[p | high][q | low] += b[j][p][q];
                    }
                }
            }
            if (type == 3)
            {
                for (int p = 0; p <= 1; p++)
                {
                    for (int q = 0; q <= 1; q++)
                    {
                        tmp[p ^ high][q ^ low] += b[j][p][q];
                    }
                }
            }

            b[j] = tmp;
        }
        int ans = 0;
        for (int j = 1; j <= 30; j++)
        {
            ans += b[j][0][1];
        }
        cout << ans << endl;
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
