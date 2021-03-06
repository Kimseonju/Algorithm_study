﻿// 2178beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int x, y;
vector<string> vec;
queue<pair<int, int>>q;
int dx[4] = { 1,0,-1,0 };
//오 아 왼 위
int dy[4] = { 0,1,0,-1 };
int check[101][101];
int main()
{
	cin >> y >> x;

	for (int i = 0; i < y; ++i)
	{
		string str;
		cin >> str;
		vec.push_back(str);
	}
	q.push({ 0,0 });
	check[0][0] = 0;
	while (!q.empty())
	{
		int ty =q.front().first;
		int tx =q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int cy = ty + dy[i];
			int cx = tx + dx[i];
			
			if (cy<0 || cy>=y || cx<0 || cx>=x)
				continue;
			if (vec[cy][cx]=='1'&& check[cy][cx] == 0)
			{ 
				check[cy][cx] = check[ty][tx] + 1;
				q.push({ cy,cx });
			}
		}

	}
	cout << check[y - 1][x - 1]+1;
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
