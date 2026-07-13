#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;

void solve()
{
    int n, c;
    cin >> n >> c;

    vector value(n + 1, vector<int>(32, 0));
    for (int i = 0; i < c; i++)
    {
        int e, f, l;
        cin >> e >> f >> l;

        int fear = 0, like = 0;
        for (int j = 0; j < f; j++)
        {
            int x;
            cin >> x;
            fear |= 1 << ((x - e + n) % n);
        }
        for (int j = 0; j < l; j++)
        {
            int y;
            cin >> y;
            like |= 1 << ((y - e + n) % n);
        }

        for (int mask = 0; mask < 32; mask++)
        {
            bool happy = (mask & fear) || ((mask & like) != like);
            value[e][mask] += happy;
        }
    }

    int ans = 0;
    for (int first = 0; first < 16; first++)
    {
        vector<int> dp(16, INF);
        dp[first] = 0;

        for (int i = 5; i <= n; i++)
        {
            vector<int> ndp(16, INF);
            for (int mask = 0; mask < 16; mask++)
            {
                if (dp[mask] == INF)
                {
                    continue;
                }
                for (int x = 0; x <= 1; x++)
                {
                    int five = mask | (x << 4);
                    int next_mask = (mask >> 1) | (x << 3);
                    ndp[next_mask] = max(ndp[next_mask], dp[mask] + value[i - 4][five]);
                }
            }
            dp = ndp;
        }

        for (int last = 0; last < 16; last++)
        {
            int sum = dp[last];
            sum += value[n - 3][last | ((first & 1) << 4)];
            sum += value[n - 2][(last >> 1) | ((first & 3) << 3)];
            sum += value[n - 1][(last >> 2) | ((first & 7) << 2)];
            sum += value[n][(last >> 3) | (first << 1)];
            ans = max(ans, sum);
        }
    }

    cout << ans << '\n';
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
