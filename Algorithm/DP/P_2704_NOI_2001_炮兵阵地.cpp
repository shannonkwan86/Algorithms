#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> land(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        string row;
        cin >> row;

        for (int j = 0; j < m; j++)
        {
            int x = (row[j] == 'P');
            land[i] = (land[i] << 1) | x;
        }
    }

    vector<int> states;
    vector<int> cnt(1 << m, 0);

    for (int s = 0; s < (1 << m); s++)
    {
        if ((s & (s << 1)) == 0 && (s & (s << 2)) == 0)
        {
            states.push_back(s);
            cnt[s] = __builtin_popcountll(s);
        }
    }

    vector<vector<int>> dp(1 << m, vector<int>(1 << m, -1));
    vector<vector<int>> ndp(1 << m, vector<int>(1 << m, -1));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int a = 0; a < (1 << m); a++)
        {
            fill(ndp[a].begin(), ndp[a].end(), -1);
        }

        for (int old : states)
        {
            for (int pre : states)
            {
                if (dp[old][pre] == -1)
                    continue;

                for (int cur : states)
                {
                    if ((cur & land[i]) != cur)
                        continue;

                    if ((cur & pre) != 0)
                        continue;

                    if ((cur & old) != 0)
                        continue;

                    ndp[pre][cur] = max(ndp[pre][cur],
                                        dp[old][pre] + cnt[cur]);
                }
            }
        }

        dp.swap(ndp);
    }

    int ans = 0;

    for (int pre : states)
    {
        for (int cur : states)
        {
            ans = max(ans, dp[pre][cur]);
        }
    }

    cout << ans << '\n';
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