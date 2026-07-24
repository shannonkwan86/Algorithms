#include <bits/stdc++.h>
using namespace std;
/*int d[100005];
int host[100005];
int host2[100005];
int num[100005];*/
void solve()
{
    int n, maxn = 0;
    cin >> n;
    vector<int> d(n + 5, 0);
    vector<int> host(n + 5, 0);
    vector<int> host2(n + 5, 0);
    vector<int> num(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        num[d[i]]++;
        maxn = max(maxn, d[i]);
        if (host[d[i]] == 0)
        {
            host[d[i]] = i;
        }
        else if (host2[d[i]] == 0)
        {
            host2[d[i]] = i;
        }
    }
    if (host2[maxn / 2 + 1] == 0)
    {
        host2[maxn / 2 + 1] = host[maxn / 2 + 1];
    }
    int safe = 0;
    for (int i = maxn / 2 + 1; i <= maxn; i++)
    {
        safe += num[i];
        if (i == maxn / 2 + 1)
        {
            if (num[i] > 1 && maxn % 2 == 1)
            {
                cout << "No" << endl;
                return;
            }
            else if (num[i] > 2 && maxn % 2 == 0)
            {
                cout << "No" << endl;
                return;
            }
        }
        if (num[i] < 2)
        {
            if (i == maxn / 2 + 1 && maxn % 2 == 1)
            {
                continue;
            }
            else
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    if (safe != n)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for (int i = maxn; i > maxn / 2 + 1; i--)
    {
        cout << host[i] << " " << host[i - 1] << endl;
    }
    for (int i = maxn; i > maxn / 2 + 1; i--)
    {
        cout << host2[i] << " " << host2[i - 1] << endl;
    }
    if (host[maxn / 2 + 1] != host2[maxn / 2 + 1] && host2[maxn / 2 + 1] != 0)
    {
        cout << host[maxn / 2 + 1] << " " << host2[maxn / 2 + 1] << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if (host[d[i]] == i)
            continue;
        if (host2[d[i]] == i)
            continue;
        cout << i << " " << host[d[i] - 1] << endl;
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}