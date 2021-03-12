// 10159beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int INF = 100000000;
int N, M;
int map[101][101];
int ans[101];
int main()
{
	cin >> N >> M;
	int a, b;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = INF;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 2;
	}
	
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (map[i][k] + map[k][j] == 2)
					map[i][j] = 1;
				if (map[i][k] + map[k][j] == 4)
					map[i][j] = 2;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
				continue;
			if (map[i][j] == INF)
				cnt++;
		}
		ans[i] = cnt;
		cnt = 0;
	}
	for (int i = 1; i <= N; ++i)
	{
		cout << ans[i] << "\n";
	}
}
