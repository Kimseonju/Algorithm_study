#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, X;
int d[1001];
vector<pair<int, int>>a[1001];
int answer = 0;
void dijkstra(int start, int end)
{
	if (end == 0)
		end = X;
	d[start] = 0;
	priority_queue<pair<int, int>>pq; //앞에꺼먼저 비교함
	pq.push(make_pair(0, start));
	if (start == end)
		return;


	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (d[current] < distance) continue;
		{
			for (int i = 0; i < a[current].size(); ++i)
			{
				int next=a[current][i].first;
				int nextdistance = a[current][i].second + distance;
				if (nextdistance < d[next])
				{
					d[next] = nextdistance;
					if (next == end)
						break;
					pq.push(make_pair(-nextdistance, next));
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M >> X;
	//집에서 X까지의 거리
	for (int i = 0; i < M; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		a[start].push_back(make_pair(end, cost));
	}
	for (int i = 1; i < N+1; ++i)
	{
		for (int j = 0; j < N+1; ++j)
			d[j] = 987654321;
		dijkstra(i, 0);
		int ans = d[X];

		for (int j = 0; j < N + 1; ++j)
			d[j] = 987654321;
		dijkstra(X, i);
		ans += d[i];
		if (answer < ans)
			answer = ans;
	}
	cout << answer;
}