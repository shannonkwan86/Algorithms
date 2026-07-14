#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    vector<int> pi(k);
    vector<int> spi(k);
    for (int i = 1; i < k; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
        {
            j = pi[j - 1];
        }
        if (s[j] == s[i])
        {
            j++;
        }
        pi[i] = j;
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (pi[i] == 0)
        {
            spi[i] = 0;
        }
        else if (spi[pi[i] - 1] != 0)
        {
            spi[i] = spi[pi[i] - 1];
        }
        else
        {
            spi[i] = pi[i];
        }
        if (spi[i] != 0)
        {
            ans += (i + 1) - spi[i];
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}