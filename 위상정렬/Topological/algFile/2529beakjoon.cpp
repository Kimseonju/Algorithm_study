// 2529beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int k;
vector<int>v[10];
int indegree[10];
int revdegree[10];
int result[10];
int result2[10];
int main()
{
	cin >> k;
	char temp;
	for (int i = 0; i < k; ++i)
	{
		cin >> temp;
		if (temp == '<')
		{
			v[i].push_back(i + 1);{
			indegree[i+1]++;
			revdegree[i + 1]++;

			}
		}
		else
		{
			v[i+1].push_back(i);
			indegree[i]++;
			revdegree[i]++;
		}
	}

	priority_queue<int> q;
	priority_queue<int> q2;
	for (int i = 0; i < k+1; ++i)
	{
		if (indegree[i] == 0){
			q.push(-i);
			q2.push(i);
		}
	}
	int cnt = 0;
	for (int i = 0; i < k+1; i++)
	{
		int x=-q.top();
		q.pop();
		result[x] = cnt++;
		
		for (int j = 0; j < v[x].size(); ++j)
		{
			int next = v[x][j];
			if (--indegree[next] == 0)
				q.push(-next);
		}
	}
	cnt = 0;
	for (int i = 0; i < k + 1; i++)
	{
		int x = q2.top();
		q2.pop();
		result2[x] = cnt++;

		for (int j = 0; j < v[x].size(); ++j)
		{
			int next = v[x][j];
			if (--revdegree[next] == 0)
				q2.push(next);
		}
	}
	for (int i = 0; i < k + 1; i++) {
		cout << result2[i] + 9 - k;
	}
	cout << "\n";
	for (int i = 0; i < k + 1; i++) {
		cout << result[i];
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
