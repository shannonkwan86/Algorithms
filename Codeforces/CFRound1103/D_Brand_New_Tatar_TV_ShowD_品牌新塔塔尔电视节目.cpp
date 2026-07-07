#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<int> lose(n + k + 5, 0);

    int bad = 0; 
    bool ok = false;

    for (int i = n; i >= 1; i--)
    {
        if (i + 1 <= n && lose[i + 1])
            bad++;
        if (i + k + 1 <= n && lose[i + k + 1])
            bad--;

        if (cnt[i] == 0)
            continue;

        if (bad == 0 && cnt[i] % 2 == 1)
        {
            lose[i] = 1;
        }

        if (!lose[i])
        {
            ok = true;
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
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