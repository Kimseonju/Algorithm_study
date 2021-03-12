// 3055baekjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;


int R, C;
//R은 세로 C는 가로
string map[51];
queue<pair<pair <int, int>, int>> animal;
queue<pair<int, int>> water;
bool banimal = false;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 500;
int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; ++i)
	{
		cin >> map[i];
	}
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (map[i][j] == 'S')
			{
				animal.push({{ i,j }, 0});
				banimal = true;
				break;
			}
		}
		if (banimal)
			break;
	}
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (map[i][j] == '*')
			{
				water.push({ i,j });
			}
		}
	}

	while (!animal.empty())
	{
		int watersize = water.size();
		for (int i = 0; i < watersize; ++i) 
		{
			int waterdy = water.front().first;
			int waterdx = water.front().second;
			water.pop();
			for (int k = 0; k < 4; ++k) 
			{
				int chy = dy[k] + waterdy;
				int chx = dx[k] + waterdx;
				if (chx < C && chx > -1 && chy > -1 && chy < R)
				{
					if(map[chy][chx]=='.' || map[chy][chx]=='k'){
						map[chy][chx] = '*';
						water.push({ chy,chx });
					}
				}
			}
		}

		int animalsize = animal.size();
		for (int i = 0; i < animalsize; ++i) 
		{
			int animaldy = animal.front().first.first;
			int animaldx = animal.front().first.second;
			int animalCount = animal.front().second;
			animal.pop();
			animalCount++;
			for (int k = 0; k < 4; ++k)
			{
				int chy = dy[k] + animaldy;
				int chx = dx[k] + animaldx;
				if (chx < C && chx > -1 && chy > -1 && chy < R)
				{
					if (map[chy][chx] == '.') 
					{
						map[chy][chx] = 'k';
						animal.push({ {chy,chx}, animalCount});
					}
					if (map[chy][chx] == 'D')
					{
						if (animalCount < ans) 
						{
							ans = animalCount;
						}
					}
				}
			}
		}
	}
	
	if (ans == 500)
		cout << "KAKTUS";
	else
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
