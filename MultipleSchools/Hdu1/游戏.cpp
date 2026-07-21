#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    vector<int> pre(n + 1);
    pre[0] = 0;
    vector<int> suf(n + 1);
    suf[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1];
        pre[i] += x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        suf[i] = suf[i - 1];
        suf[i] += x[n + 1 - i];
    }

    int mid = (n + 1) / 2;
    // bool ok;

    if (n == 1)
    {
        cout << "NO\n";
        return;
    }
    if (n == 2)
    {
        cout << "YES\n";
        return;
    }
    if (n % 2 == 0)
    {
        if (pre[mid] >= suf[mid - 1])
        {
            cout << "YES\n";
            return;
        }
    }
    else
    {
        if (pre[mid - 1] > suf[mid - 1])
        {
            cout << "YES\n";
            return;
        }
        else if (pre[mid - 1] == suf[mid - 1])
        {
            int cnt = 1;
            while (pre[cnt] == suf[cnt] && cnt < mid - 1)
                cnt++;
            if (pre[cnt] > suf[cnt])
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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