// 1504beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
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
int N, M;
vector<Edge>v[801];
int stN, stM;
int visit[801];
void Dijkstra(int a)
{
	queue<int> q;
	q.push(a);
	visit[a] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); ++i)
		{
			if (visit[x] + v[x][i].dir < visit[v[x][i].node])
			{
				visit[v[x][i].node] = visit[x] + v[x][i].dir;
				q.push(v[x][i].node);
			}
			
		}
	}

	
}
int main()
{
	cin >> N >> M;
	int a1, a2, a3;
	bool bone, btwo;
	bone = true;
	btwo = true;
	for (int i = 0; i < M; ++i)
	{
		cin >> a1 >> a2 >> a3;
		v[a1-1].push_back(Edge(a2-1,a3));
		v[a2 - 1].push_back(Edge(a1 - 1, a3));
	}
	for (int i = 0; i < N; ++i)
	{
		visit[i] = 900000000;
	}
	cin >> stN>> stM;

	stN--;
	stM--;
	Dijkstra(0);
	long long  temp1 = visit[stN]; //1번째까지
	long long  temp2 = visit[stM]; //2번째까지
	if (temp1 != 900000000 && temp2 != 900000000)
	{
		for (int i = 0; i < N; ++i)
		{
			visit[i] = 900000000;
		}

		Dijkstra(stN); //1번
		long long  temp1_1 = visit[stM];//1->2
		long long  end2 = visit[N - 1]; //1번에서 목적지
		for (int i = 0; i < N; ++i)
		{
			visit[i] = 900000000;
		}

		Dijkstra(stM);//2번
		long long  temp2_1 = visit[stN];// 2->1
		long long  end1 = visit[N - 1]; //2번에서 목적지

		long long one = temp1 + temp1_1 + end1;
		long long two = temp2 + temp2_1 + end2;
		long long ans = one > two ? two : one;
		cout << ans;
	}
	else
		cout << "-1";
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
