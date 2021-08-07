
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

long long int inf = 9223372036854775800;
vector<vector<pair<int, long long int>>> a;

long long int dist[10001][21];

int N, M, K;
void dijkstra(int start)
{
	dist[1][0] = 0;
	priority_queue<tuple<long long int,  int, int>>pq;
	pq.push(make_tuple(0, 1, 0));


	while (!pq.empty())
	{
		int current = get<1>(pq.top());
		long long int distance = -get<0>(pq.top());;
		int step= get<2>(pq.top());
		pq.pop();

		if (dist[current][step] < distance)
			continue;

		dist[current][step] = distance;
		for (int i = 0; i < a[current].size(); ++i)
		{
			int next = a[current][i].first;
			long long int dis = dist[current][step] + a[current][i].second;

			if (step + 1 <= K && dist[next][step + 1] > dist[current][step]) {
				dist[next][step + 1] = dist[current][step];
				pq.push(make_tuple(-dist[next][step + 1] , next, step + 1));
			}
			if (dist[next][step] > dis) {
				dist[next][step] = dis;
				pq.push(make_tuple(-dist[next][step] , next, step));
			}

		}
	}

}


int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= K; ++j)
		{
			dist[i][j] = inf;
		}
	}
	a.resize(N + 1);

	int one, two, three;
	for (int i = 0; i < M; ++i)
	{
		cin >> one >> two >> three;
		a[one].push_back(make_pair(two, three));
		a[two].push_back(make_pair(one, three));
		
	}
	dijkstra(1);

	long long int ans = inf;
	for (int i = 1; i <= K; ++i)
	{
		if (ans > dist[N][i])
			ans = dist[N][i];
	}
	cout << ans;

}
