#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int tot = 0;

    for (int &x : a)
    {
        cin >> x;
        tot ^= x;
    }

    
    array<int, 63> bs{};

    auto insert = [&](int val)
    {
        for (int bit = 62; bit >= 0; --bit)
        {
            if (((val >> bit) & 1LL) == 0)
                continue;

            if (bs[bit])
            {
                val ^= bs[bit];
            }
            else
            {
                bs[bit] = val;
                return;
            }
        }
    };

    for (int x : a)
        insert(x & ~tot);
 
    int best = 0;

    for (int bit = 62; bit >= 0; --bit)
        best = max(best, best ^ bs[bit]);

    
    cout << tot + 2 * best << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}