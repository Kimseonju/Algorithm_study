
#include <iostream>
#include <queue>
#include <memory.h>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
int map[101][101];
int d[101][101];
int check[101][101];
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf_s("%1d", &map[i][j]);
			d[i][j] = 999999;
		}
	}

	queue<pair<int,int>> q;
	
	q.push(make_pair(0, 0));
	d[0][0] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int cx = x + dx[i];
			int cy = x + dy[i];
 			if (cx<0 || cx> n || cy<0 || cy>m)
				continue;

			if (map[cx][cy] == 1)
			{
				if (d[cx][cy] > d[x][y]+1) 
				{
					d[cx][cy] = d[x][y] + 1;
					q.push(make_pair(cx, cy));
				}
					
				
				
			}
			else
			{
				if (d[cx][cy] > d[x][y]) 
				{
					d[cx][cy] = d[x][y];
					q.push(make_pair(cx, cy));
				}
			}

		}

	}

	cout << d[m - 1][n - 1];
}
