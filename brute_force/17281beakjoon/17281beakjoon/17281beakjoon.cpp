// 17281beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
using namespace std;
int N;
int in[51][11];
int base[3];
int outCount;
int playnum;
bool game[11];
int ans;
vector<int> vec;
int playgame()
{
	int check = 0;
	playnum = 0;
	vec.insert(vec.begin() + 3, 1);
	for (int i = 1; i <= N; ++i)
	{//이닝

		memset(base, 0, sizeof(base));
		for (;; ++playnum)
		{
			if (playnum == vec.size())
				playnum = 0;
			if (in[i][vec[playnum]] == 0)
			{
				outCount++;
				if (outCount == 3)
				{
					playnum++;
					if (playnum == vec.size())
						playnum = 0;
					outCount = 0;
					break;
				}
			}

			if (in[i][vec[playnum]] == 1)
			{
				if (base[2] == 1){
					check++;
					base[2] = 0;
				}
				base[2] = base[1];
				base[1] = base[0];
				base[0] = 1;
			}
			if (in[i][vec[playnum]] == 2)
			{
				if (base[2] == 1){
					check++;
					base[2] = 0;
				}
				if (base[1] == 1){
					check++;
					base[1] = 0;
				}
				base[2] = base[0];
				base[0] = 0;
				base[1] = 1;
			}
			if (in[i][vec[playnum]] == 3)
			{
				if (base[2] == 1) {
					check++;
					base[2] = 0;
				}
				if (base[1] == 1) {
					check++;
					base[1] = 0;
				}
				if (base[0] == 1) {
					check++;
					base[0] = 0;
				}
				base[2] = 1;
			}
			if (in[i][vec[playnum]] == 4)
			{
				if (base[2] == 1) {
					check++;
					base[2] = 0;
				}
				if (base[1] == 1) {
					check++;
					base[1] = 0;
				}
				if (base[0] == 1) {
					check++;
					base[0] = 0;
				}
				check++;
			}
		}
	}

	vec.erase(vec.begin() + 3);
	return check;
}
void DFS(int cnt)
{
	if (cnt == 8)
	{
		int num = playgame();
		if (ans < num)
			ans = num;
	}
	else{
		for (int j = 2; j <= 9; ++j)
		{
			if (game[j] == true)
				continue;
			vec.push_back(j);
			game[j] = true;
			DFS(cnt + 1);
			vec.pop_back();
			game[j] = false;
		}
	}

}
int main()
{
	cin >> N;
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			cin >> in[i][j];
		}
	}

	outCount = 0;
	game[1] = true;
	DFS(0);

	cout << ans;
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
