// 2610beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
//체크 못품
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int map[101][101];
int N, M;
int max1[101];
bool check[101];
vector<int> minTime(101, 100000000), teamMaster(101, 0), answer;


int main()
{
	cin >> N >> M;
	int a, b;
	vector<int> arr;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			map[i][j] = (i == j ? 0 : 100000000);
		}
		check[i] = false;
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][k] + map[k][j] < map[i][j])
					map[i][j] = map[i][k] + map[k][j];

			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int groupNum = 100000000, MaxTime = -1;

		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] != 100000000)
			{
				if (groupNum == 100000000) groupNum = j; //입력안되있으면 입력
				if (MaxTime < map[i][j]) MaxTime = map[i][j]; //최대값구하기
			}
		}
		if (minTime[groupNum] > MaxTime)  //의사전달 시간의 최대값보다 최소값이 더 낮으면
		{
			minTime[groupNum] = MaxTime;
			teamMaster[groupNum] = i;
		}
	}

	for (int i = 1; i <= N; i++)
		if (teamMaster[i])
			answer.push_back(teamMaster[i]);

	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";
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
