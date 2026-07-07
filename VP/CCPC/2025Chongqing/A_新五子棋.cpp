#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int col[N][N];
int vis[N][N];

int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, 0, 1, -1};

void setStone(int x, int y, int c, int tt)
{
    col[x][y] = c;
    vis[x][y] = tt;
}

int getStone(int x, int y, int tt)
{
    if (x < 1 || y < 1 || x > 1000 || y > 1000 || vis[x][y] != tt)
    {
        return -1;
    }
    return col[x][y];
}

void solve(int tt)
{
    int n;
    cin >> n;

    int ansBlack = 0;
    int ansWhite = 0;

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;

        int c = (i + 1) % 2;
        setStone(x, y, c, tt);

        int add = 0;

        for (int d = 0; d < 4; d++)
        {
            for (int b = -4; b <= 0; b++)
            {
                bool ok = true;

                for (int k = b; k <= b + 4; k++)
                {
                    int nx = x + dx[d] * k;
                    int ny = y + dy[d] * k;

                    if (getStone(nx, ny, tt) != c)
                    {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                {
                    add++;
                }
            }
        }

        if (c == 0)
        {
            ansBlack += add;
            cout << ansBlack << ' ';
        }
        else
        {
            ansWhite += add;
            cout << ansWhite << ' ';
        }
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tt = 1; tt <= T; tt++)
    {
        solve(tt);
    }

    return 0;
}