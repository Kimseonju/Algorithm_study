// 17141beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct XY {
	XY(int iy, int ix)
	{
		y = iy;
		x = ix;
	}
	int x, y;
};
int map[50][50];
bool bplaypoint[10];
bool bVisit[50][50];
int N, M;
vector<XY>vPoint;
vector<XY>vplayPoint;
int idir[4][4] = { {1,0},{-1,0},{0,-1},{0,1} };
int ans = 50000;
bool mapcheck()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == 1)continue;
			if (bVisit[i][j] == false)
				return false;
		}
	}
	return true;
}
void playcheck()
{
	queue<XY>q;
	for (int i = 0; i < vplayPoint.size(); ++i)
	{
		q.push(vplayPoint[i]);
		bVisit[vplayPoint[i].y][vplayPoint[i].x] = true;
	}
	int cnt = 0;
	while (!q.empty())
	{
		int isize=q.size();
		for (int i = 0; i < isize; ++i)
		{
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int j = 0; j < 4; ++j)
			{
				int nexty = y+idir[j][0];
				int nextx = x+idir[j][1];
				if (nexty >= 0 && nexty < N && nextx >= 0 && nextx < N)
				{
					if (bVisit[nexty][nextx] == false && map[nexty][nextx] != 1)
					{
						bVisit[nexty][nextx] = true;
						q.push(XY(nexty, nextx));
					}
				}
			}
		}
		if (q.size() != 0)cnt++;
	}
	if (mapcheck())
	{
		if (ans > cnt)
			ans = cnt;
	}
}
void playpoint(int idx, int cnt)
{
	if (cnt == M)
	{
		memset(bVisit, 0, sizeof(bVisit));
		playcheck();
		return;
		//실행
	}
	for (int i = idx; i < vPoint.size(); ++i)
	{
		if (bplaypoint[i] == true)
			continue;
		bplaypoint[i] = true;
		vplayPoint.push_back(vPoint[i]);
		playpoint(i, cnt + 1);
		bplaypoint[i] = false;
		vplayPoint.pop_back();

	}
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				XY a(i,j);
				vPoint.push_back(a);
			}
		}
	}
	playpoint(0, 0);
	if (ans == 50000)
		cout << "-1";
	else
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
