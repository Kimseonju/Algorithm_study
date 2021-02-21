// 1719beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
             //노드 타임
vector<pair<int, int>>house[201];
int inDegree[201];
int n, m;
int visit[201];
int trace[201];
//다익스트라로 하나씩 훑어봐주면서 짧은 거리순으로 입력
void Dijkstra(int a)
{
	queue<int> q;
	q.push(a);
	visit[a] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < house[x].size(); ++i)
		{
			if (visit[x] + house[x][i].second < visit[house[x][i].first])
			{
				visit[house[x][i].first] = visit[x] + house[x][i].second;
				q.push(house[x][i].first);
				if (trace[x] == 0)
					trace[house[x][i].first] = house[x][i].first;
				else
					trace[house[x][i].first] = trace[x];
			}

		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (a == i)
			cout << "- ";
		else
			cout << trace[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i <= n; ++i){
		visit[i] = 100000000;
		trace[i] = 0;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, time;
		cin >> a >> b >> time;
		house[a].push_back({b, time});
		house[b].push_back({ a, time });
		inDegree[a]++;
	}
	for (int i = 0; i <= n; ++i)
		visit[i] = 100000000;
	for (int i = 1; i <= n; ++i)
	{
		Dijkstra(i);
	}
}
