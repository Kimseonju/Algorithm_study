// 1753beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
int V, E;
int K;
using namespace std;
int visit[20000];
class Edge {
public:
	int node;
	int dir;
	Edge(int a, int b)
	{
		node = a;
		dir = b;
	}
};
vector<Edge>v[20000];
priority_queue<pair<int, int>> pq;
void Dijkstra(int cost, int node)
{
	pq.push(make_pair(cost, node));
	visit[node] = 0;
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (visit[here] < cost) continue;
		for (int i = 0; i < v[here].size(); ++i)
		{
			int nextnode = visit[here] + v[here][i].dir;
			if (nextnode < visit[v[here][i].node])
			{
				visit[v[here][i].node] = nextnode;
				pq.push(make_pair(-nextnode,v[here][i].node));
			}

		}
	}
}
int main()
{
	cin >> V >> E;

	cin >> K;
	int ia, ib, ic;
	for (int i = 0; i < E; ++i)
	{
		cin >> ia >> ib >> ic;
		v[ia - 1].push_back(Edge(ib-1, ic));
		//v[ib - 1].push_back(Edge(ia-1, ic));
	}

	for (int i = 0; i < V; ++i)
	{
		visit[i] = 900000000;
	}
	Dijkstra(0, K - 1);

	for (int i = 0; i < V; ++i)
	{
		if (visit[i] == 900000000)
			cout << "INF\n" ;
		else
			cout << visit[i]<<"\n";
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
