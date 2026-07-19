#include <bits/stdc++.h>
using namespace std;
#define int long long

// 设 cnt 是所有不同位置中，a[i] = 1 的数量。
//  a == b：答案为 0
//  cnt 是奇数：答案为 1
//  a 全是 0：答案为 -1
//  b 全是 1：答案为 -1
//  其余情况：答案为 2

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    int cnta = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    vector<int> dif;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
        {
            dif.push_back(i);
            if (a[i] == 1)
            {
                cnta++;
            }
        }
    }
    // int sum = 0;
    if (dif.size() == 0)
    {
        cout << 0 << endl;
        return;
    }

    if (cnta % 2 == 1)
    {
        cout << 1 << endl;
        return;
    }

    bool all0 = true;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            all0 = false;
        }
    }
    if (all0)
    {
        cout << -1 << endl;
        return;
    }
    bool ball1 = true;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 0)
        {
            ball1 = false;
        }
    }
    if (ball1)
    {
        cout << -1 << endl;
        return;
    }
    cout << 2 << endl;
    // int cnt = 0;
    // for (int i : dif)
    // {
    //     if (a[i] == 1)
    //     {
    //         cnt++;
    //     }
    // }
    // if (cnt == 0)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    // if(cnt%2==1){
    //     cout<<1<<endl;
    //     return;
    // }
    // else{
    //     cout<<2<<endl;
    //     return;
    // }
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