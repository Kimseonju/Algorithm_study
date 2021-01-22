// 2573beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include<cstring>
using namespace std;
int map[301][301] = { 0 };
int savemap[301][301] = { 0 };
int map_y;
int map_x;
queue<pair<int, int>>q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool visit[301][301] = { false };

int ice_water(int y, int x)
{
	int cnt = 0;

	for (int i = 0; i < 4; ++i)
	{
		int cy = y + dy[i];
		int cx = x + dx[i];
		if (map[cy][cx] == 0)
			cnt++;
	}
	return cnt++;
}

void bfs(int y, int x) //섬갯수 한타일 다 true
{
	q.push({ y,x });
	visit[y][x] = true;
	while (!q.empty())
	{
		int qy = q.front().first;
		int qx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int cy = qy + dy[i];
			int cx = qx + dx[i];
			if (cy < 0 || cy >= map_y || cx < 0 || cx >= map_x) continue;

			if (map[cy][cx] > 0 && !visit[cy][cx])
			{
				visit[cy][cx] = true;
				q.push({ cy,cx });
			}
		}
	}
}
int main()
{
	cin >> map_y >> map_x;

	for (int i = 0; i < map_y; ++i)
	{
		for (int j = 0; j < map_x; ++j)
		{
			cin >> map[i][j];
		}
	}
	int land = 0;
	int year = 0;
	for(;;)
	{
		land = 0;
		memset(savemap, 0, sizeof(savemap));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < map_y; ++i)
		{
			for (int j = 0; j < map_x; ++j)
			{
				if (map[i][j] != 0 && !visit[i][j]){
					land++;
					bfs(i, j);
				}
			}
		}

		if (land > 1)
			break;
		if (land == 0)
		{
			year = 0;
			break;
		}


		for (int i = 0; i < map_y; ++i)
		{
			for (int j = 0; j < map_x; ++j)
			{
				if (map[i][j] > 0)
				{
					int cnt=ice_water(i, j);
					savemap[i][j] = map[i][j] - cnt;
					if (savemap[i][j] < 0)
						savemap[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < map_y; ++i)
		{
			for (int j = 0; j < map_x; ++j)
			{
				map[i][j] = savemap[i][j];
			}
		}
		year++;
	}
	cout << year;
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
