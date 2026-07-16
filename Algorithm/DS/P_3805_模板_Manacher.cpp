#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    // ^ 和 $ 是不同的边界哨兵，# 用来统一奇偶回文。
    string t;
    t.reserve(s.size() * 2 + 3);
    t.push_back('^');
    for (char ch : s) {
        t.push_back('#');
        t.push_back(ch);
    }
    t.push_back('#');
    t.push_back('$');

    vector<int> p(t.size(), 0);
    int center = 0;
    int right = 0; // 当前已知回文的最右下标，采用包含式边界
    int answer = 0;

    for (int i = 1; i + 1 < static_cast<int>(t.size()); ++i) {
        if (i < right) {
            int mirror = 2 * center - i;
            p[i] = min(p[mirror], right - i);
        }

        // 只比较初始安全半径之外的下一对字符。
        while (t[i - p[i] - 1] == t[i + p[i] + 1]) {
            ++p[i];
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        answer = max(answer, p[i]);
    }

    cout << answer << '\n';
    return 0;
}