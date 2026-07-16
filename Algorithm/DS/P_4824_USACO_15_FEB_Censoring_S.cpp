#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    string t;
    cin >> s >> t;

    // 预处理t,找它的pi；
    // 预处理模式串 t 的前缀函数
    int m = t.size();
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j && t[i] != t[j])
        {
            j = pi[j - 1];
        }

        if (t[i] == t[j])
        {
            j++;
        }

        pi[i] = j;
    }

    string ans;
    vector<int> state;
    int len = s.size();
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        // ans += s[i];

        char b = s[i];
        while (cnt && t[cnt] != b)
        {
            cnt = pi[cnt - 1];
        }
        if (t[cnt] == b)
        {
            cnt++;
        }
        ans.push_back(b);
        state.push_back(cnt);
        if (cnt == m)
        {
            for (int i = 0; i < m; i++)
            {
                ans.pop_back();
                state.pop_back();
            }

            // 恢复删除后的 KMP 状态
            if (state.empty())
            {
                cnt = 0;
            }
            else
            {
                cnt = state.back();
            }
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