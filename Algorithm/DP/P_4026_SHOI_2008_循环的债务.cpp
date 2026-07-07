#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    vector<int> typ = {100, 50, 20, 10, 5, 1};
    vector<int> a(6);
    vector<int> b(6);
    vector<int> c(6);
    int tot = 0;
    int suma = 0, sumb = 0, sumc = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
        tot += a[i] * typ[i];
        suma += a[i] * typ[i];
    }
    for (int i = 0; i < 6; i++)
    {
        cin >> b[i];
        tot += b[i] * typ[i];
        sumb += b[i] * typ[i];
    }
    for (int i = 0; i < 6; i++)
    {
        cin >> c[i];
        tot += c[i] * typ[i];
        sumc += c[i] * typ[i];
    }

    suma = suma - x1 + x3;
    sumb = sumb - x2 + x1;
    sumc = sumc - x3 + x2;

    if (suma < 0 || sumb < 0 || sumc < 0)
    {
        cout << "impossible\n";
        return;
    }
    const int INF = 4e18;
    vector dp(tot + 1, vector<int>(tot + 1, INF));
    dp[0][0] = 0;
    vector<vector<int>> all = {a, b, c};

    for (int owner = 0; owner < 3; owner++)
    {
        for (int kind = 0; kind < 6; kind++)
        {
            int value = typ[kind];

            for (int k = 0; k < all[owner][kind]; k++)
            {
                vector ndp(tot + 1, vector<int>(tot + 1, INF));

                for (int i = 0; i <= tot; i++)
                {
                    for (int j = 0; i + j <= tot; j++)
                    {
                        if (dp[i][j] == INF)
                        {
                            continue;
                        }
                        if (i + value <= tot)
                        {
                            ndp[i + value][j] = min(ndp[i + value][j], dp[i][j] + (owner != 0));
                        }

                        if (j + value <= tot)
                        {
                            ndp[i][j + value] = min(ndp[i][j + value], dp[i][j] + (owner != 1));
                        }

                        ndp[i][j] = min(ndp[i][j], dp[i][j] + (owner != 2));
                    }
                }
                dp = ndp;
            }
        }
    }
    int ans = dp[suma][sumb];

    if (ans >= INF)
    {
        cout << "impossible\n";
    }
    else
    {
        cout << ans << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}