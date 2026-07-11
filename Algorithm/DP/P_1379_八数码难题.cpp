#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin >> s;
    string end = "123804765";
    queue<string> q;
    unordered_map<string, int> dis;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    q.push(end);
    dis[end] = 0;

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        if (cur == s)
        {
            cout << dis[cur] << '\n';
            return;
        }

        int pos = cur.find('0');
        int x = pos / 3, y = pos % 3;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;

            string nxt = cur;
            swap(nxt[pos], nxt[nx * 3 + ny]);
            if (!dis.count(nxt))
            {
                dis[nxt] = dis[cur] + 1;
                q.push(nxt);
            }
        }
    }
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
