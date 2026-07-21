#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Trie
{
    static constexpr int ALPHABET = 26;

    struct Node
    {
        array<int, ALPHABET> next;
        vector<int> ids;
        int last;
        bool end;
    };

    vector<Node> t;

    Trie()
    {
        init();
    }

    void init()
    {
        t.assign(2, Node());
        t[0].next.fill(1);
    }

    int newNode()
    {
        t.push_back({{},{},0,0});
        return (int)t.size() - 1;
    }
};
void solve()
{
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