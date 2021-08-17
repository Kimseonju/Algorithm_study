#include <iostream>


int dist[1001][1001][3];
bool check[1001][1001];
int map[1001][1001];
using namespace std;
int N, M;
int dx[3] = { 0,-1,1 };
int dy[3] = { 1,0,0 };

int dp(int x, int y, int dir)
{
    if (y == N - 1 && x == M - 1)
        return map[N - 1][M - 1];

    int& ref = dist[y][x][dir];
    if (ref != -1000000)
        return ref;

    for (int i = 0; i < 3; ++i)
    {
        int nextx = dx[i] + x;
        int nexty = dy[i] + y;

        if (check[nexty][nextx])
            continue;
        if (nextx < 0 || nexty < 0 || nextx >= M || nexty >= N)
            continue;

        check[nexty][nextx] = true;
        ref=max(ref, dp(nextx, nexty, i)+ map[y][x]);
        check[nexty][nextx] = false;
    }
    return ref;
}
int main()
{
    cin >> N >> M;
    //y
    for (int i = 0; i < N; ++i)
    {  //x
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
            for(int k=0; k<3; ++k)
            dist[i][j][k] = -1000000;
        }
    }
    check[0][0] = true;
    int bbb=dp(0, 0, 1);
    cout << bbb;

}

