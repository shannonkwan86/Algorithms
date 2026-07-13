#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int pw[N];

void solve()
{
    int n;
    cin >> n;

    map<int, int> mp;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    int ans = 1;

    for (auto [x, y] : mp)
    {
        ans = ans * pw[y - 1] % mod;
    }

    if (mp.find(-1) == mp.end())
    {
        cout << ans << endl;
        return;
    }

    int cnt = 0;

    for (auto it = mp.begin(); next(it) != mp.end(); ++it)
    {
        const auto &[key, value] = *it;
        const auto &[nextKey, nextValue] = *next(it);

        if (key > 0 && key + 1 == nextKey)
        {
            cnt++;
        }
    }

    ans = ans * (cnt + 1) % mod;

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    pw[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pw[i] = pw[i - 1] * 2 % mod;
    }

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
