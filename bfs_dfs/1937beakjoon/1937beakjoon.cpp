﻿// 1937beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;
int yx;
int map[500][500];
int dp[500][500];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
queue<pair<int, int>>q;
int ans = 0;
int dfs(int y, int x)
{
	if (dp[y][x] != 0)
		return dp[y][x];

	dp[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ky = y + dy[i];
		int kx = x + dx[i];

		if (ky < 0 || ky >= yx || kx < 0 || kx >= yx) continue;
		if (map[y][x] < map[ky][kx])
		{
			int cnt = dfs(ky,kx)+1;
			if (dp[y][x] < cnt)
				dp[y][x] = cnt;
		}
	}
	return dp[y][x];
}
int main()
{
	cin >> yx;

	for (int i = 0; i < yx; ++i)
	{
		for (int j = 0; j < yx; ++j)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < yx; ++i)
	{
		for (int j = 0; j < yx; ++j)
		{
			int cnt =dfs(i, j);

			if (ans < cnt)
				ans = cnt;
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
