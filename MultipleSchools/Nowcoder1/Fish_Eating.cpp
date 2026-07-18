#include <bits/stdc++.h>
using namespace std;
#define int long long

// const int N = 2e5 + 5;
// int a[N];
// int fa[N];

// int find(int x)
// {
//     if (fa[x] != x)
//         fa[x] = find(fa[x]);
//     return fa[x];
// }

// bool isSame(int x, int y)
// {
//     return find(x) == find(y);
// }

// void Union(int x, int y)
// {
//     fa[find(x)] = find(y);
// }

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    int l = 0;
    for (int i = 1; i <= q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x1, y1, v;
            cin >> x1 >> y1 >> v;
            
        }
        else
        {
            int x1, y1;
            cin >> x1 >> y1;
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