

#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int x, y;
ll map[1500][1500];
ll dp[1500][1500];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    vector<int> v;
    for (int i = 1; i <= x; ++i)
    {
        for (int j = 1; j <= y; ++j)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= x; ++i)
    {
        for (int j = 1; j <= y; ++j)
        {

            dp[i][j] = map[i][j] + dp[i][j - 1] + dp[i - 1][j] + -dp[i-1][j-1];

        }
    }
    int anscnt = 0;
    cin >> anscnt;
    for (int i = 0; i < anscnt; ++i)
    {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll ans = dp[x2][y2]-dp[x2][y1 - 1]-dp[x1 - 1][y2]+dp[x1 -1][y1 -1];
        cout << ans << '\n';
    }
}