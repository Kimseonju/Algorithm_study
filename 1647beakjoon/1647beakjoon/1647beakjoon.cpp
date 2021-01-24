// 1647beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>
//마을을 두개로 분리
//
//분리된 마을안에 있는 두집 사이에 경로가 존재
//
//두 마을 사이에 있는 길은 삭제
//
//각 분리된 집 안에서 두집 경로 항상존재 1개
//
//최소
//
//결론 -모든 길을 하나만 연결 후 마지막 길(제일 높은 값) 삭제
int N, M;
class Edge {
public:
	int node[2];
	int direction;

	Edge(int a, int b, int dir)
	{
		node[0] = a;
		node[1] = b;
		direction = dir;
	}
	bool operator<(Edge &edge)
	{
		return direction < edge.direction;
	}
};
vector<Edge>v;
int parent[100000];
int getparent(int num)
{
	if (parent[num] == num)
		return num;
	else
		return parent[num] = getparent(parent[num]);
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
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b >> c;
		v.push_back(Edge(a, b, c));
	}
	int MaxM = N - 1; //이어져있는 길의 갯수값
	int cnt = 0;
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		parent[i] = i;
	}
	for (int i = 0; i < v.size(); ++i)
	{
		if (!findparent(v[i].node[0] - 1, v[i].node[1] - 1))
		{
			cnt++;
			if (MaxM == cnt)
			{ //마지막선 더하지 않는다.
				break;
			}
			sum += v[i].direction;
		}
	}
	cout << sum;
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
