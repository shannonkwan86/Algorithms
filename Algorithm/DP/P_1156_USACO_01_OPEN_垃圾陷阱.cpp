#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

struct obj
{
    int t, f, h;
};

bool cmp(obj &a, obj &b)
{
    return a.t < b.t;
}

void solve()
{
    int D, G;
    cin >> D >> G;

    vector<obj> objs(G + 1);
    for (int i = 1; i <= G; i++)
    {
        cin >> objs[i].t >> objs[i].f >> objs[i].h;
    }

    sort(objs.begin() + 1, objs.end(), cmp);
    vector<int> dp(D + 1, -1);

    dp[0] = 10;
    for (int i = 1; i <= G; i++)
    {
        for (int j = D - 1; j >= 0; j--)
        {
            if (dp[j] >= objs[i].t)
            {
                if (j + objs[i].h >= D)
                {
                    cout << objs[i].t << endl;
                    return;
                }
                dp[j + objs[i].h] = max(dp[j + objs[i].h], dp[j]);
                dp[j] = max(dp[j], dp[j] + objs[i].f);
            }
        }
    }
    int ans = 0;
    for (int j = D - 1; j >= 0; j--)
    {
        ans = max(ans, dp[j]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}