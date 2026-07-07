#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
// #define int long long

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n + 1);
    vector<int> y(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= k; i++)
    {
        int p, l, h;
        cin >> p >> l >> h;
        mp[p] = {l, h};
    }
    const int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        int tx = x[i], ty = y[i];

        // 上升：点击一次或多次
        for (int j = tx + 1; j <= m + tx; j++)
        {
            int nj = min(j, m);
            dp[i][nj] = min(dp[i][nj], dp[i - 1][j - tx] + 1);
            dp[i][nj] = min(dp[i][nj], dp[i][j - tx] + 1);
        }

        // 下降：不点击
        for (int j = 1; j + ty <= m; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i - 1][j + ty]);
        }

        // 管道限制：最后处理
        if (mp.count(i))
        {
            int l = mp[i].first, h = mp[i].second;
            for (int j = 1; j <= m; j++)
            {
                if (j <= l || j >= h)
                    dp[i][j] = INF;
            }
        }
    }
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = cnt[i - 1];
        if (mp.count(i))
        {
            cnt[i]++;
        }
    }

    int ans = INF;
    for (int j = 1; j <= m; j++)
    {
        ans = min(ans, dp[n][j]);
    }
    if (ans < INF)
    {
        cout << 1 << endl;
        cout << ans << endl;
    }
    else
    {
        cout << 0 << endl;
        for (int i = n; i > 0; i--)
        {
            for (int j = 1; j <= m; j++)
            {
                if (dp[i][j] < INF)
                {
                    cout << cnt[i] << endl;
                    return;
                }
            }
        }
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
