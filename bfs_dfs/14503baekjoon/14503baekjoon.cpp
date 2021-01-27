// 14503baekjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int y, x;
int rob_y;
int rob_x;
int rob_dir;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int map[51][51] = { 1 };
bool visit[51][51] = { false };
int ans = 0;

int backx[4] = { 0, -1, 0, 1 };
int backy[4] = { 1, 0, -1, 0 };
void dfs(int vrob_y, int vrob_x, int vdir) {

	if (map[vrob_y][vrob_x] == 0)
	{
		map[vrob_y][vrob_x] = 2;
		ans++;
	}

	for (int i = 0; i < 4; ++i)
	{
		vdir = vdir - 1;
		if (vdir < 0)
			vdir = 3;

		int cy = vrob_y + dy[vdir];
		int cx = vrob_x + dx[vdir];
		if (cy < 0 || cy >= y || cx < 0 || cx >= x)
			continue;
		if (map[cy][cx] == 0)
		{
			dfs(cy, cx, vdir);
			return;
		}

	}

	if (map[vrob_y + backy[vdir]][vrob_x + backx[vdir]] == 1) return;
	else dfs(vrob_y + backy[vdir], vrob_x + backx[vdir], vdir);
}
int main()
{
	cin >> y >> x;
	cin >> rob_y >> rob_x >> rob_dir;
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			cin >> map[i][j];
		}
	}
	dfs(rob_y, rob_x, rob_dir);


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
