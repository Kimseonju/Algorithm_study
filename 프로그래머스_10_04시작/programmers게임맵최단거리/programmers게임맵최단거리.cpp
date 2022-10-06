#include<vector>
#include <queue>
#include <tuple>
using namespace std;
int MoveCount[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<tuple<int, int, int>> q;
    int n = maps.size();
    int m = maps[0].size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            MoveCount[i][j] = 50000;
        }
    }
    MoveCount[0][0] = 1;
    q.push(make_tuple(0, 0, 1));
    while (!q.empty())
    {
        int Y = get<0>(q.front());
        int X = get<1>(q.front());
        int NowMoveCount = get<2>(q.front());
        q.pop();
        if (NowMoveCount > MoveCount[Y][X])
            continue;
        for (int i = 0; i < 4; ++i)
        {
            int NextX = dx[i] + X;
            int NextY = dy[i] + Y;
            if (NextY < 0 || NextY >= n || NextX < 0 || NextX >= m)
                continue;
            if (maps[NextY][NextX] == 0)
                continue;
            if (MoveCount[NextY][NextX] > NowMoveCount + 1)
            {
                MoveCount[NextY][NextX] = NowMoveCount + 1;
                q.push(make_tuple(NextY, NextX, NowMoveCount + 1));
            }
        }
    }
    answer = MoveCount[n - 1][m - 1];
    if (answer == 50000)
        return -1;
    else
        return answer;
}