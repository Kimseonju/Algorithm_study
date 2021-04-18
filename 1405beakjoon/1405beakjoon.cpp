// 1405beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int num;

double dir[4];
double ans;
bool icheck[30][30];
int idir[4][4] = { {1,0},{-1,0},{0,-1},{0,1} };
void dps(int inum, double chance, int x, int y)
{
	if (inum == num)
	{
		ans += chance;
		return;
	}
	icheck[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		int nextx = x + idir[i][0];
		int nexty = y + idir[i][1];

		if (!icheck[nextx][nexty])
		{
			dps(inum + 1, chance*dir[i], nextx, nexty);
			icheck[nextx][nexty] = false;
		}
	}

}

int main()
{
	cin >> num;

	for (int i = 0; i < 4; ++i)
	{
		double a;
		cin >> a;
		dir[i] = a * 0.01;
	}


	dps(0, 1, 15, 15);
	cout << ans;
}