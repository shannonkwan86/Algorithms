#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    int num0 = 0;
    int num1 = 0;
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] == 0)
            num0++;
        else if (p[i] == 1)
            num1++;
        else
            a.push_back(p[i]);
    }
    sort(a.begin(), a.end());

    int ans = 1;
    int d = k - 1;
    int sz = a.size();

    if (sz == 0)
    {
        if (num1 > 0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
        return;
    }

    const int MOD = 998244353;

    // m%(k-1)=1

    int cnt;
    for (int i = 0;; i++)
    {
        if (i * (k - 1) + 1 <= sz + num1 && i * (k) + 1 > sz + num1)
        {
            cnt = i;
            break;
        }
    }
    int drop = 0;
    while (drop <= sz)
    {
        int take = (sz - drop);
        int need = (1 - take % d + d) % d;
        if (need <= num1)
        {
            break;
        }
        else
        {
            drop++;
        }
    }
    if (drop == sz)
    {
        if (num1 > 0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
        return;
    }

    for (int i = drop; i < sz; i++)
    {
        ans = ans * a[i] % MOD;
    }

    cout << ans << '\n';
    // // 每次减少k-1个数，减少到最后要小于k个数。
    // int cnt = n / (k - 1);
    // int num = n - (cnt - 1) * (k - 1);
    // if (num >= k)
    // {
    //     num -= (k - 1);
    // }
    // // cerr << cnt << " " << num << endl;
    // ans = ans * p[n] % MOD;
    // for (int i = n - 1; i >= num; i--)
    // {
    //     if (p[i] != 0)
    //         ans = ans * p[i] % MOD;
    //     else
    //         break;
    // }
    // cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}