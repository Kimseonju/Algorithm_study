// 4386beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// 루트 sqrt();
//두 변 거리의 루트값이 제일 적은것으로 정렬을 해야한다.
//별마다 0, 1, 2의 번호를 달고, 부모를 만든다
//다 연결이 가능하므로 모든 가능성을 열어둔다.
//만약 1,2,3의 별이 있으면 1-> 2,3  2->3 이런형식으로 만들어야댄다.


class Node 
{
public:
	int start;
	int end;
	double direction;
	Node(int start, int end ,double direction)
	{
		this->start = start;
		this->end = end;
		this->direction = direction;
	}
	bool operator<(Node &node)
	{
		return direction < node.direction;
	}
};

int num;
float star[100][2];
int parent[100];
vector<Node>v;

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
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		cin >> star[i][0] >> star[i][1];
	}

	for (int i = 0; i < num; ++i)
	{
		for (int j = i+1; j < num; ++j)
		{
			int tempx = abs(star[i][0] - star[j][0]);
			int tempy = abs(star[i][1] - star[j][1]);
			v.push_back(Node(i, j, sqrt((tempx*tempx) + (tempy*tempy))));
		}
		parent[i] = i;
	}
	sort(v.begin(), v.end());
	double sum=0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (!findparent(v[i].start, v[i].end))
		{
			sum += v[i].direction;
			unionparent(v[i].start, v[i].end);
		}
	}
	cout.setf(ios::fixed);
	cout.precision(2);
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
