#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef std::pair<int, int> PII;

void solve(void)
{
    // int n = 2, m = 5;
    int n, m;
    cin >> n >> m;
    std::vector<std::vector<int>> arr(n + 1, std::vector<int>(m + 1));
    std::vector<int> num = {0, 1, 2};
    int cnt = 0;
    auto dfs = [&](auto &dfs, int h, int w, std::vector<std::vector<int>> curr) -> void
    {
        if (h == 1 && w == m + 1)
        {
            cnt++;
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            if (w != 1)
            {
                if (curr[h][w - 1] == num[i])
                {
                    continue;
                }
            }
            if (h != 1)
            {
                if (curr[h - 1][w] == num[i])
                {
                    continue;
                    
                }
            }
            curr[h][w] = num[i];

            //            for (int i = 1; i <= n; i++) {
            //                for (int j = 1; j <= m; j++) {
            //                    std::cout << arr[i][j] << " ";
            //                }
            //                std::cout << '\n';
            //            }
            //            std::cout << "-----" << std::endl;

            if (h == n)
            {
                dfs(dfs, 1, w + 1, curr);
            }
            else
            {
                dfs(dfs, h + 1, w, curr);
            }

            //            for (int i = 1; i <= n; i++) {
            //                for (int j = 1; j <= m; j++) {
            //                    std::cout << arr[i][j] << " ";
            //                }
            //                std::cout << '\n';
            //            }
            //            std::cout << "-----" << '\n';
        }
    };
    dfs(dfs, 1, 1, arr);
    std::cout << cnt << '\n';
}
signed main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //    std::cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}