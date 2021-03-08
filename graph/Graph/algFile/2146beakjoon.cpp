// 2146beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <queue>
#include <cstring>

int map[101][101];
int N;
int mapnum=2;
queue<pair<int, int>>map_q;
queue<pair<int, int>>q;
int dx[4] = { 0, 0, 1, -1 }; 
int dy[4] = { 1, -1, 0, 0 };
int visit[101][101] = { false };
int ans = 100000;
void bfs_map(int y, int x)
{
	q.push({ y,x });
	while (!q.empty())
	{

		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;

			if (map[ny][nx] == 1 && !visit[ny][nx])
			{
				map[ny][nx] = mapnum;
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

void dfs(int y, int x, int imapnum)
{
	
	if (imapnum != map[y][x] && map[y][x]!=0)
	{
		if (ans > visit[y][x])
		{
			ans = visit[y][x];
		}
		return;
	}

	int cy = y;
	int cx = x;
	
	for (int i = 0; i < 4; ++i)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
			
			
		if (visit[ny][nx] >= visit[cy][cx] + 1 || visit[ny][nx] == 0)
		{
			visit[ny][nx] = visit[cy][cx] + 1;
			dfs(ny, nx, imapnum);
			visit[ny][nx] = visit[cy][cx] - 1;
		}
	}
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i) //y
	{
		for (int j = 0; j < N; ++j) //x
		{
			cin >> map[i][j];
			
		}
	}
	for (int i = 0; i < N; ++i) //y
	{
		for (int j = 0; j < N; ++j) //x
		{
			if (map[i][j] == 1)
			{
				map[i][j] = mapnum;
				bfs_map(i, j);
				mapnum++;
			}
		}
	}
	for (int i = 0; i < N; ++i) //y
	{
		for (int j = 0; j < N; ++j) //x
		{
			//cin >> map[i][j];
			if (map[i][j] != 0)
			{
				memset(visit, 0, sizeof(visit));
				dfs(i, j, map[i][j]);
			}
		}
	}


	int numaaaa;
	cout << ans-1;
}
