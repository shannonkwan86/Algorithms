#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> info(n + 1);
    vector<set<int>> edge(n + 1);
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        edge[u].insert(v);
        edge[v].insert(u);
    }
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> t[i];
    }
	
	for(int i = 1; i <= n; i++){
		for(auto & vv : edge[i]){
			info[i]++;
			info[vv]++;
		}
	}
	for(int i = 1; i <= n; i++){
		info[i] /= 2;
	}
	
    vector<PII> ans;
    vector<int> ok(n+1);

    int index = 1;
    auto dfs = [&](auto dfs, int curr) -> void {
        if(ok[curr] == 0){
            for (int v : edge[curr]){
                info[v]--;
            }
			ok[curr] = 1;
        }

        if (info[curr] == 0){   
            return;
        }

        if (edge[curr].find(t[index]) == edge[curr].end()){
            ans.push_back({curr, t[index]});
        }

		dfs(dfs, t[index++]);
		dfs(dfs, curr);
    };

    for(int i = 1; i <= n; i++){
        if(ok[t[i]] == 0){
            index++;
            dfs(dfs,t[i]);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
// 6 6
// 1 3
// 1 4
// 2 3
// 3 4
// 3 6
// 5 6
// 1 2 3 4 5 6