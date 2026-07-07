#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long
struct BIT
{
    int n;
    vector<int> tree;
    BIT(int n1)
    {
        n = n1;
        tree.assign(n + 1, 0);
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void add(int idx, int num)
    {
        while (idx <= n)
        {
            tree[idx] += num;
            idx += lowbit(idx);
        }
    }
    int sum(int idx)
    {
        int res = 0;
        while (idx > 0)
        {
            res += tree[idx];
            idx -= lowbit(idx);
        }
        return res;
    }
    int query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    BIT Col(q + 1);
    BIT Row(q + 1);
    vector<int> rowTime(n + 1, 0);
    vector<int> colTime(n + 1, 0);

    int ans = 0;
    Row.add(1, n);
    Col.add(1, n);

    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            int R = b;
            ans += n - Col.sum(rowTime[R]);
            Row.add(rowTime[R] + 1, -1);
            rowTime[R] = i;
            Row.add(rowTime[R] + 1, +1);
        }
        else
        {
            int C = b;
            ans -= n - Row.sum(colTime[C] + 1);
            Col.add(colTime[C] + 1, -1);
            colTime[C] = i;
            Col.add(colTime[C] + 1, +1);
        }
        cout << ans << endl;
    }
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