#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi(n);
    vector<int> depth(n + 1);
    depth[0] = 0;
    depth[1] = 1;
    for (int i = 1; i < n; i++)
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
        depth[i + 1] = depth[pi[i]] + 1;
    }

    int ans = 1;
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        // int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
        {
            j = pi[j - 1];
        }
        if (s[j] == s[i])
        {
            j++;
        }
        int len = i + 1;
        while (j * 2 > len)
        {
            j = pi[j - 1];
        }
        ans = ans * (depth[j] + 1) % MOD;
    }
    cout << ans << endl;
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