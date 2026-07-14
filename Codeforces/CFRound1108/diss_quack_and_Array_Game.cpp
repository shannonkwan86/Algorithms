#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 4e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = inf;
    for (int k = 0; k <= 17; k++)
    {
        int pw = 1LL << k;
        int total = k; // 前 k 次全数组除以 2

        for (int i = 1; i <= n; i++)
        {
            int b0 = (a[i] + pw - 1) / pw * pw;
            int best = inf;

            for (int b = b0; b <= b0 + 32; b += pw)
            {
                int bits = __lg(b) + 1;

                int cost = (b - a[i]) + __builtin_popcountll(b) + bits - k - 1;

                best = min(best, cost);
            }

            total += best;
        }

        ans = min(ans, total);
    }
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