
#include <iostream>
#include <queue>
using namespace std;

int su;
int suman;

bool check[100001];
int dist[100001];
int main()
{
	cin >> su >> suman;

	queue<int> q;
	q.push(su);

	check[su] = true;
	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		if (pos == suman)
			continue;

		if (pos - 1 >= 0) {
			if (!check[pos - 1] ) 
			{
				q.push(pos - 1);
				check[pos - 1] = true;
				dist[pos - 1] = dist[pos] + 1;
			}
		}
		if (pos + 1 < 100001)
		{
			if (!check[pos + 1])
			{
				q.push(pos + 1);
				check[pos + 1] = true;
				dist[pos + 1] = dist[pos] + 1;
			}
		}
		
		if (pos * 2 < 100001)
		{
			if (!check[pos * 2])
			{
				if (pos * 2 < 200000)
				{
					q.push(pos * 2);
					check[pos * 2] = true;
					dist[pos * 2] = dist[pos] + 1;

				}

			}
		}
		
		
	}
	cout << dist[suman];
}
