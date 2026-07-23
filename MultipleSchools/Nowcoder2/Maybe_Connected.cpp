#include <bits/stdc++.h>
using namespace std;
#define int long long

// const int N = 1e5 + 5;
// int pre[N];
// int cm(int a, int b)
// {
//     int ans = pre[a] / pre[b];
//     ans /= pre[a - b];
//     return ans;
// }
void solve()
{
    int n, m;
    cin >> n >> m;
    if (m <= n - 1)
    {
        cout << m * (m - 1) / 2 << "\n";
        // cout << cm(m, 2) << "\n";
        return;
    }
    int ans = (n - 1) * (n - 2) / 2;
    m -= (n - 1);
    while (m--)
    {
        ans -= 1;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    // pre[1] = 1;
    // for (int i = 2; i <= N; i++)
    // {
    //     pre[i] = pre[i - 1] * i;
    // }
    // cerr<<cm(2,2)<<endl;
    while (t--)
    {
        solve();
    }
    return 0;
}