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
    bool win;

    if (n % 2 == 0)
    {
        // n = 2k：先比较前 i 堆与后 i-1 堆，i 从 k 向 2 递减
        win = true; // 若全部相等，Alice 必胜
        for (int i = n / 2; i >= 2; --i)
        {
            if (pre[i] != suf[i - 1])
            {
                win = (pre[i] > suf[i - 1]);
                break;
            }
        }
    }
    else
    {
        // n = 2k+1：比较前 i 堆与后 i 堆，i 从 k 向 1 递减
        win = false; // 若全部相等，Alice 必败
        for (int i = n / 2; i >= 1; --i)
        {
            if (pre[i] != suf[i])
            {
                win = (pre[i] > suf[i]);
                break;
            }
        }
    }

    cout << (win ? "YES\n" : "NO\n");
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