#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

struct axb
{
    int a;
    int b;
};

bool cmp(axb t1, axb t2)
{
    if (t1.a == t2.a)
    {
        return t1.b < t2.b;
    }
    return t1.a < t2.a;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a1(n + 1);
    vector<int> b1(n + 1);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b1[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    vector<axb> line1(n + 1);
    vector<int> line2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        line1[i].a = a1[i];
        line1[i].b = b1[i];
        line2[i] = c[i];
    }
    sort(line1.begin() + 1, line1.end(), cmp);
    sort(line2.begin() + 1, line2.end());
    auto good = [&](long long a, long long b, long long c, long long x) -> bool
    {
        return (__int128)a * c + b >= x;
    };

    auto check = [&](long long x) -> bool
    {
        int need = (n + 1) / 2;
        vector<pair<int, int>> seg;

        for (int i = 1; i <= n; i++)
        {
            long long a = line1[i].a;
            long long b = line1[i].b;

            if (a > 0)
            {
                int L = 1, R = n, pos = n + 1;

                while (L <= R)
                {
                    int mid = (L + R) / 2;
                    if (good(a, b, line2[mid], x))
                    {
                        pos = mid;
                        R = mid - 1;
                    }
                    else
                    {
                        L = mid + 1;
                    }
                }

                if (pos <= n)
                    seg.push_back({pos, n});
            }
            else if (a < 0)
            {
                int L = 1, R = n, pos = 0;

                while (L <= R)
                {
                    int mid = (L + R) / 2;
                    if (good(a, b, line2[mid], x))
                    {
                        pos = mid;
                        L = mid + 1;
                    }
                    else
                    {
                        R = mid - 1;
                    }
                }

                if (pos >= 1)
                    seg.push_back({1, pos});
            }
            else
            {
                if (b >= x)
                    seg.push_back({1, n});
            }
        }

        sort(seg.begin(), seg.end(), [](auto p1, auto p2)
             {
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second; });

        set<int> unused;
        for (int i = 1; i <= n; i++)
            unused.insert(i);

        int cnt = 0;
        for (auto [l, r] : seg)
        {
            auto it = unused.lower_bound(l);
            if (it != unused.end() && *it <= r)
            {
                cnt++;
                unused.erase(it);
                if (cnt >= need)
                    return true;
            }
        }

        return false;
    };
    int l = -4e18, r = 4e18;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << r << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}