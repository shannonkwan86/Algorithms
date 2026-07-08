#include <bits/stdc++.h>
using namespace std;
// #define int long long

void solve()
{
    int n;  
    cin >> n;
    vector<double>p(n+1);

    vector<double>a(n+1);
    vector<double>b(n+1);
    vector<double>f(n+1);

    for(int i=1;i<=n;i++){
        cin>>p[i];       
    }

    for(int i=1;i<=n;i++)
	{
       
       a[i]=(a[i-1]+1)*p[i];
       b[i]=(b[i-1]+2*a[i-1]+1)*p[i];
       f[i]=f[i-1]+(3*b[i-1]+3*a[i-1]+1)*p[i];
   }
   cout << fixed << setprecision(1) << (double)f[n] << '\n';
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