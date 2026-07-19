#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    if (k > n || k > m)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES" << endl;

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = m / k;
    }
    ans[k] += m % k;

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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