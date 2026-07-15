#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> d(n + 1);
    vector<int> pre1(n + 1, 0), pre0(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {

        d[i] = ((s[i - 1] - '0') != (i % 2));

        pre1[i] = pre1[i - 1];
        pre0[i] = pre0[i - 1];

        if (d[i] == 1 && (i == 1 || d[i - 1] == 0))
        {
            pre1[i]++;
        }

        if (d[i] == 0 && (i == 1 || d[i - 1] == 1))
        {
            pre0[i]++;
        }
    }

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int ans1 = pre1[r] - pre1[l] + (d[l] == 1);
        int ans2 = pre0[r] - pre0[l] + (d[l] == 0);
        if (min(ans1, ans2) <= k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
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