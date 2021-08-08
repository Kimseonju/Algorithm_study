
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<vector<pair<int, int>>> city;
int n, m, k;

//이걸 왜 300이라고 하면 왜 틀리는거지..?
priority_queue<int> dist[20000];

void dijstra()
{

	priority_queue<pair<int, int>>pq;
	pq.push(make_pair(0, 1));
	dist[1].push(0);
	while (!pq.empty())
	{
		int time = -pq.top().first;
		int location = pq.top().second;

		pq.pop();

		for (int i = 0; i < city[location].size(); ++i)
		{
			int next_time = city[location][i].second +time;
			int next_location = city[location][i].first;
			
			if (dist[next_location].size() < k || dist[next_location].top() > next_time)
			{
				if (dist[next_location].size() == k)
					dist[next_location].pop();
				dist[next_location].push(next_time);
				pq.push(make_pair(-next_time, next_location));
			}

		}


	}



}

int main()
{
	cin >> n >> m >> k;


	city.resize(n + 1);

	int city1, city2, citytime;
	for (int i = 0; i < m; ++i)
	{
		cin >> city1 >> city2 >> citytime;

		city[city1].push_back(make_pair(city2, citytime));
	}
	dijstra();

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() != k) {
			cout << "-1" << '\n';
		}
		else {
			cout << dist[i].top() << '\n';
		}
	}

}
