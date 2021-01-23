// 1197beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Edge 
{
public:
	int node[2];
	int direction;

	Edge(int a, int b, int dir)
	{
		node[0] = a;
		node[1] = b;
		direction = dir;
	}
	
	bool operator<(Edge& edge)
	{
		return direction < edge.direction;
	}
};
int V, E;
vector<Edge>v;
int parent[10000];
int getparent(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = getparent(parent[a]);
}

void unionparent(int a, int b)
{
	a = getparent(a);
	b = getparent(b);
	if (a < b)parent[b] = a;
	else
		parent[a] = b;
}
int findparent(int a, int b)
{
	int pa = getparent(a);
	int pb = getparent(b);
	if (pa == pb)
		return 1;
	else
		return 0;
}

int main()
{
	cin >> V;
	cin >> E;
	int a, b, c;
	for (int i = 0; i < E; ++i)
	{
		cin >> a >> b >> c;
		v.push_back(Edge(a, b, c));
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < V; ++i)
		parent[i] = i;
	int sum = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (!findparent(v[i].node[0] - 1, v[i].node[1] - 1))
		{
			sum += v[i].direction;
			unionparent(v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	cout << sum;

	return 0;
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
