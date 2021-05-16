#include <iostream>
#include <string>
#include <cstring>
#include <queue>
int N;
int map[126][126];
int d1[126][126];
using namespace std;

int dest[4][2] = { {0,1},{0,-1}, {-1,0}, {1,0} };
int main()
{
	// j는 x y는 i
	int a = 0;
	for (;;)
	{
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> map[i][j];
				d1[i][j] = 987654321;
			}
		}    
		d1[0][0] = map[0][0];
		priority_queue<pair<int, pair<int,int>>> PQ;
		PQ.push(make_pair(-d1[0][0], make_pair(0,0)));


		while (!PQ.empty())
		{
			int Cost = -PQ.top().first;
			int y = PQ.top().second.first;
			int x = PQ.top().second.second;
			PQ.pop();

			for (int i = 0; i < 4; ++i)
			{
				int cy=y+dest[i][0];
				int cx=x+dest[i][1];
				if (cy<0 || cy>=N || cx<0 || cx>=N)
					continue;
				if (d1[cy][cx] > Cost + map[cy][cx])
				{
					d1[cy][cx] = Cost + map[cy][cx];
					PQ.push(make_pair(-d1[cy][cx], make_pair(cy, cx)));
				}
			}
		}
		++a;
		printf("Problem %d: %d\n", a, d1[N - 1][N - 1]);
		//string 값변환 ㄴㄴ
	}
}
