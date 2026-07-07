#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> vs(H + 1);
    // vector<vector<int>> pre(H + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= H; i++)
    {

        cin >> vs[i];
        vs[i] = " " + vs[i];
    }

    int ans = 0;
    for (int i = 1; i <= H; i++)
    {
        vector<int> col(W + 1);

        for (int ii = i; ii <= H; ii++)
        {
            for (int j = 1; j <= W; j++)
            {
                col[j] += (vs[ii][j] == '1');
            }

            auto count_leq = [&](int x)
            {
                if (x < 0)
                    return 0LL;

                int l = 1;
                int sum = 0;
                int res = 0;

                for (int r = 1; r <= W; r++)
                {
                    sum += col[r];

                    while (sum > x)
                    {
                        sum -= col[l];
                        l++;
                    }

                    res += r - l + 1;
                }

                return res;
            };

            ans += count_leq(K) - count_leq(K - 1);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}