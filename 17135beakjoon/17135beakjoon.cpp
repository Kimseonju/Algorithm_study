// 17135beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> v;
int N, M, D;
int map[16][16];
int tempmap[16][16];
int killmap[16][16];
int monster;
bool select[16];
int ans;
int kill(int monster, int round)
{
	if (round == N)
		return monster;
	for(int a=0; a<M; ++a)
	{
		bool check = false;
		if (!select[a])
			continue;

		for (int i = N-1; i >= 0; --i)
		{
			int yCnt = N-i-1;
			int Dcount = D - yCnt-1;
			int count = 0;
			for (int j = a;; --j)
			{
				if (j < 0)
					break;
				if (check)
					break;
				if (Dcount < count)
					break;
				if (tempmap[i][j] == 1)
				{
					check = true;
					killmap[i][j] = 1;
					break;
				}
				count++;
			}
			count = 0;
			for (int j = a;; ++j)
			{
				if (j >= M)
					break;
				if (check)
					break;
				if (Dcount < count)
					break;
				if (tempmap[i][j] == 1)
				{
					check = true;
					killmap[i][j] = 1;
					break;
				}
				count++;
			}
			if (check)
				break;
		}
	}

	for (int i = N-1; i >=0; --i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (killmap[i][j] == 1)
			{
				monster++;
				tempmap[i][j] = 0;
			}
			if (!(i + 1 == N)){
				tempmap[i + 1][j] = tempmap[i][j];
			}
			else
			{
				tempmap[i][j] = 0;
			}
		}
	}
	memset(&killmap, 0, sizeof(killmap));
	kill(monster, round+1);
}

void dp(int idx, int cnt)
{
	if (cnt == 3)
	{
		//플레이
		memcpy(tempmap, map, sizeof(map));
		int monster=kill(0,0);
		if (ans < monster)
			ans = monster;

	}
	else
	{
		for (int i = idx; i < M; ++i)
		{
			if (select[i])
				continue;
			select[i] = true;
			dp(i, cnt + 1);
			select[i] = false;
		}
	}
}


int main()
{
	cin >> N >> M >> D;
	    // y    x
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				++monster;
		}
	}
	dp(0, 0);
	cout << ans;
}