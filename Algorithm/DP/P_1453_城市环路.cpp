#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, val[N];
vector<int> g[N];
double k;

// ---------- Union-Find ----------
int fa[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

// ---------- Tree DP (iterative to avoid stack overflow) ----------
long long dp[N][2];

// Returns max sum when banning edge (ban_u, ban_v) and forcing root not selected.
long long solve(int root, int ban_u, int ban_v) {
    vector<int> order;          // DFS pre-order
    vector<int> parent(n + 1);  // parent in DFS tree
    vector<int> stk;

    stk.push_back(root);
    parent[root] = -1;

    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();
        order.push_back(u);

        for (int v : g[u]) {
            if (v == parent[u]) continue;
            if ((u == ban_u && v == ban_v) || (u == ban_v && v == ban_u)) continue;
            parent[v] = u;
            stk.push_back(v);
        }
    }

    // Bottom-up DP
    for (auto it = order.rbegin(); it != order.rend(); ++it) {
        int u = *it;
        dp[u][0] = 0;
        dp[u][1] = val[u];

        for (int v : g[u]) {
            if (v == parent[u]) continue;
            if ((u == ban_u && v == ban_v) || (u == ban_v && v == ban_u)) continue;
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }

    return dp[root][0];
}

// ---------- Main ----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        fa[i] = i;
    }

    int S = 0, T = 0;  // endpoints of the extra edge on the cycle
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;  // 0-indexed → 1-indexed
        if (find(u) == find(v)) {
            S = u, T = v;
        } else {
            fa[find(u)] = find(v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    cin >> k;

    // Add the cycle edge
    g[S].push_back(T);
    g[T].push_back(S);

    long long ans1 = solve(S, S, T);  // force S not selected
    long long ans2 = solve(T, S, T);  // force T not selected

    cout << fixed << setprecision(1) << max(ans1, ans2) * k << "\n";

    return 0;
}
