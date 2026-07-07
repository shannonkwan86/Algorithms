#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1];
        sum[i] += a[i];
    }

    deque<int> dq;
    dq.push_back(0);
    vector<array<int, 2>> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

        while (!dq.empty() && dq.front() < i - k)
        {
            dq.pop_front();
        }

        dp[i][1] = sum[i] + dp[dq.front()][0] - sum[dq.front()];

        while (!dq.empty() && (dp[dq.back()][0] - sum[dq.back()] < (dp[i][0] - sum[i])))
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
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