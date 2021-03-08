// 2590beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <string>
#include<cstring>
using namespace std;
string map[51];
//1. 기준을 잡는다.
//2. 기준과 갈수있는 거리를 계산한다.
//3. 최댓값으로 출력
queue<pair<int, int>> q;
queue<pair<int, int>>map_q;
int visit[51][51] = { 0 };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;
int main()
{
	int X, Y;
	cin >> Y >> X;
	for (int i = 0; i < Y; ++i)
	{
		cin >> map[i];
	}
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			if (map[i][j] == 'L')
			{
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		map_q.push({ y,x });
		memset(visit, 0, sizeof(visit));
		while (!map_q.empty())
		{
			int cy = map_q.front().first;
			int cx = map_q.front().second;
			map_q.pop();

			for (int k = 0; k < 4; ++k)
			{
				int chy = dy[k] + cy;
				int chx = dx[k] + cx;
				if (chy > -1 && chy<Y && chx>-1 && chx < X)
				{
					if (y == chy && x == chx) continue;
					if (map[chy][chx] == 'L')
					{
						if (visit[chy][chx] == 0 || visit[cy][cx] + 1 < visit[chy][chx])
						{
							visit[chy][chx] = visit[cy][cx] + 1;
							map_q.push({ chy,chx });
						}
					}
				}
			}
		}

		for (int i = 0; i < Y; ++i)
		{
			for (int j = 0; j < X; ++j)
			{
				if (ans < visit[i][j])
				{
					ans = visit[i][j];
				}
			}
		}
	}

	cout << ans;
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
