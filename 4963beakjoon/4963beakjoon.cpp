// 4963beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include<cstring>
using namespace std;


int x, y;
int map[51][51];
queue<pair<int, int>>q;
queue<pair<int, int>>eq;
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};
int ans;


int main()
{
	for (;;)
	{
		cin >> x >> y;
		memset(map, 0, sizeof(map));
		if (x == 0 && y == 0)
			break;
		for (int i = 0; i < y; ++i)
		{
			for (int j = 0; j < x; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
					q.push({ i,j });
			}
		}

		while (!q.empty())
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();
			if (map[cy][cx] == 1)
			{
				ans++;
				map[cy][cx] += ans;
			}
			eq.push({ cy,cx });
			while(!eq.empty())
			{
				int ey = eq.front().first;
				int ex = eq.front().second;
				eq.pop();
				for (int i = 0; i < 8; ++i)
				{
					int ay = ey + dy[i];
					int ax = ex + dx[i];
					if (ay < 0 || ay > y || ax < 0 || ax > x)
						continue;
					if (map[ay][ax] == 0)
						continue;
					if (map[ay][ax]==1){
						map[ay][ax] = map[ey][ex];
						eq.push({ ay,ax });
					}
				}
			}
		}
		cout << ans << "\n";
		ans = 0;
	}
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
