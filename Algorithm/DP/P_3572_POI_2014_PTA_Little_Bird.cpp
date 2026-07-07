#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        vector<int> dp(n + 1, 4e18);
        deque<int> dq;
        dq.push_back(1);
        dp[1] = 0;

        auto cmp = [&](int x, int y)
        {
            if (dp[x] == dp[y])
            {
                return d[x] >= d[y];
            }
            return dp[x] < dp[y];
        };

        for (int i = 2; i <= n; i++)
        {
            while (!dq.empty() && dq.front() < i - k)
            {
                dq.pop_front();
            }
            dp[i] = min(dp[i], dp[dq.front()] + (d[i] >= d[dq.front()]));
            while (!dq.empty() && cmp(i, dq.back()))
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        cout << dp[n] << endl;
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