// 2151beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int num;
int ans=5000;
string map[51];
queue<pair<int, int>>door;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int visit[5][50][50] = { 0 };
//arrow 0은 아래 1는 왼 2은 위 3는 오
struct Node {
	int y;
	int x;
	int dir;
	int num;
};
int main()
{	
	cin >> num;
	
	for (int i = 0; i < num; ++i)
	{
		cin >> map[i];
	}
	
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			if (map[i][j] == '#')
			{
				door.push({ i,j });
			}
	
		}
	}
	int y = door.front().first;
	int x = door.front().second;
	door.pop();

	queue<Node> q;
	for (int i = 0; i < 4; ++i)
	{
		int cy = y + dy[i];
		int cx = x + dx[i];
		if (cx<0 || cx>=num || cy<0 || cy>=num)
			continue;
		if (map[cy][cx] != '*')
		{
			q.push({ y,x,i,0 });
		}
	}

	while (!q.empty())
	{
		int qy = q.front().y;
		int qx = q.front().x;
		int qdir = q.front().dir;
		int qnum = q.front().num;
		q.pop();

		if (qdir > 3)
			qdir = 0;
		if (qdir < 0)
			qdir = 3;


		if (qy == door.front().first && qx == door.front().second)
		{
			if (ans > qnum)
				ans = qnum;
		}
		qy += dy[qdir];
		qx += dx[qdir];

		if (qy < 0 || qy >= num || qx < 0 || qx >= num)
			continue;
		if (map[qy][qx] == '*')
			continue;
		if(visit[qdir][qy][qx]>qnum || !visit[qdir][qy][qx])
		{
			visit[qdir][qy][qx] = qnum;
			q.push({ qy, qx, qdir, qnum });
		
			if (map[qy][qx] == '!')
			{

				qnum++;
				q.push({ qy, qx, qdir+1, qnum });
				q.push({ qy, qx, qdir-1, qnum });
			}
		}
	}


	cout << ans;
}






//백트래킹 시간초과
//void dfs(int y, int x, int arrow, int mirror)
//{
//
//	if (arrow == 9)
//	{
//		for (int i = 0; i < 4; ++i)
//		{
//			int cy = y + dy[i];
//			int cx = x + dx[i];
//			if (cx<0 || cx>num || cy<0 || cy>num)
//				continue;
//			if (map[cy][cx] == '.' || map[cy][cx] == '!')
//			{
//				visit[0][y][x] = true;
//				visit[1][y][x] = true;
//				visit[2][y][x] = true;
//				visit[3][y][x] = true;
//				dfs(y, x, i, mirror);
//				visit[0][y][x] = false;
//				visit[1][y][x] = false;
//				visit[2][y][x] = false;
//				visit[3][y][x] = false;
//
//			}
//		}
//	}
//	if (map[y][x] == '*')
//		return;
//
//	if (arrow == 4)
//		arrow = 0;
//	else if (arrow == -1)
//		arrow = 3;
//
//	y += dy[arrow];
//	x += dx[arrow];
//
//	if (y < 0 || y>=num || x<0 || x>=num)
//		return;
//	if(visit[arrow][y][x] == true)
//		return;
//	visit[arrow][y][x] = true;
//	dfs(y, x, arrow, mirror);
//	if (map[y][x] == '!')
//	{
//		
//		mirror++;
//		dfs(y, x, arrow + 1, mirror);
//		dfs(y, x, arrow - 1, mirror);
//	}
//	if (map[y][x] == '#')
//	{
//		if (ans > mirror)
//			ans = mirror;
//	}
//	visit[arrow][y][x] = false;
//	
//	
//	
//}
//int main()
//{
//		
//	cin >> num;
//	
//	for (int i = 0; i < num; ++i)
//	{
//		cin >> map[i];
//	}
//
//	for (int i = 0; i < num; ++i)
//	{
//		for (int j = 0; j < num; ++j)
//		{
//			if (map[i][j] == '#')
//			{
//				door.push({ i,j });
//			}
//
//		}
//	}
//
//	
//	int y = door.front().first;
//	int x = door.front().second;
//	door.pop();
//	dfs(y, x, 9, 0);
//	cout << ans;
//}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
