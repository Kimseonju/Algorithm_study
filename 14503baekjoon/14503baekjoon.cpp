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
int map[51][51];
bool visit[51][51] = { false };
int ans = 0;

int backx[4] = { 0, -1, 0, 1 };
int backy[4] = { 1, 0, -1, 0 };
void dfs(int vrob_y, int vrob_x, int vdir) {
	int k;

	if (map[vrob_y][vrob_x] == 0)
	{
		map[vrob_y][vrob_x] = 2;
		ans++;
	}

	for (int i = 0; i < 4; ++i)
	{
		int dir = vdir - 1 + i;
		if (dir > 3)
			dir = dir % 4;
		else if (dir < 0)
			dir = 4 + dir;

		int cy = vrob_y + dy[dir];
		int cx = vrob_x + dx[dir];
		if (cy < 0 || cy >= y || cx < 0 || cx >= x)
			continue;
		if (map[cy][cx] == 0)
		{
			dfs(cy, cx, dir);
			return;
		}

	}

	if (map[vrob_y + backy[vdir]][vrob_x + backx[vdir]] == 1) return;
	else dfs(vrob_y + backy[vdir], vrob_x + backx[vdir], vdir);
}
int main()
{
	//cin >> y >> x;
	//cin >> rob_y >> rob_x >> rob_dir;
	//for (int i = 0; i < y; ++i)
	//{
	//	for (int j = 0; j < x; ++j)
	//	{
	//		cin >> map[i][j];
	//	}
	//}
	y = 11;
	x = 10;
	rob_y = 7;
	rob_x = 4;
	rob_dir = 0;
	map[0][0] = 1;
	map[0][1] = 1;
	map[0][2] = 1;
	map[0][3] = 1;
	map[0][4] = 1;
	map[0][5] = 1;
	map[0][6] = 1;
	map[0][7] = 1;
	map[0][8] = 1;
	map[0][9] = 1;

	map[1][0] = 1;
	map[1][1] = 0;
	map[1][2] = 0;
	map[1][3] = 0;
	map[1][4] = 0;
	map[1][5] = 0;
	map[1][6] = 0;
	map[1][7] = 0;
	map[1][8] = 0;
	map[1][9] = 1;

	map[2][0] = 1;
	map[2][1] = 0;
	map[2][2] = 0;
	map[2][3] = 0;
	map[2][4] = 1;
	map[2][5] = 1;
	map[2][6] = 1;
	map[2][7] = 1;
	map[2][8] = 0;
	map[2][9] = 1;

	map[3][0] = 1;
	map[3][1] = 0;
	map[3][2] = 0;
	map[3][3] = 1;
	map[3][4] = 1;
	map[3][5] = 0;
	map[3][6] = 0;
	map[3][7] = 0;
	map[3][8] = 0;
	map[3][9] = 1;

	map[4][0] = 1;
	map[4][1] = 0;
	map[4][2] = 1;
	map[4][3] = 1;
	map[4][4] = 0;
	map[4][5] = 0;
	map[4][6] = 0;
	map[4][7] = 0;
	map[4][8] = 0;
	map[4][9] = 1;

	map[5][0] = 1;
	map[5][1] = 0;
	map[5][2] = 0;
	map[5][3] = 0;
	map[5][4] = 0;
	map[5][5] = 0;
	map[5][6] = 0;
	map[5][7] = 0;
	map[5][8] = 0;
	map[5][9] = 1;

	map[6][0] = 1;
	map[6][1] = 0;
	map[6][2] = 0;
	map[6][3] = 0;
	map[6][4] = 0;
	map[6][5] = 0;
	map[6][6] = 0;
	map[6][7] = 1;
	map[6][8] = 0;
	map[6][9] = 1;

	map[7][0] = 1;
	map[7][1] = 0;
	map[7][2] = 0;
	map[7][3] = 0;
	map[7][4] = 0;
	map[7][5] = 0;
	map[7][6] = 1;
	map[7][7] = 1;
	map[7][8] = 0;
	map[7][9] = 1;

	map[8][0] = 1;
	map[8][1] = 0;
	map[8][2] = 0;
	map[8][3] = 0;
	map[8][4] = 0;
	map[8][5] = 0;
	map[8][6] = 1;
	map[8][7] = 1;
	map[8][8] = 0;
	map[8][9] = 1;

	map[9][0] = 1;
	map[9][1] = 0;
	map[9][2] = 0;
	map[9][3] = 0;
	map[9][4] = 0;
	map[9][5] = 0;
	map[9][6] = 0;
	map[9][7] = 0;
	map[9][8] = 0;
	map[9][9] = 1;

	map[10][0] = 1;
	map[10][1] = 1;
	map[10][2] = 1;
	map[10][3] = 1;
	map[10][4] = 1;
	map[10][5] = 1;
	map[10][6] = 1;
	map[10][7] = 1;
	map[10][8] = 1;
	map[10][9] = 1;
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
