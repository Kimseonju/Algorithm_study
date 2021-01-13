// 2667baekjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
string map[26];
bool visit[26][26] = { false };
int num;
int dx[4] = { -1,1,0,0};
int dy[4] = { 0,0,-1,1 };

queue<pair<pair<int, int>, int>> q;
vector<int> vec_mapCount;
int mapCount;
void dfs(int x, int y)
{
	visit[y][x] = true;
	for(int i=0; i<4; ++i)
	{
		int chx = x + dx[i];
		int chy = y + dy[i];
		if (chx < num && chx > -1 && chy >-1 && chy < num)
		{
			if(map[chy][chx]=='1'&& visit[chy][chx] == false){
				mapCount++;
				dfs(chx, chy);
			}
		}
	}

}
int main()
{

	cin >> num;
	
	for (int y = 0; y < num; ++y) 
	{
			cin >> map[y];
	}

	for (int y = 0; y < num; ++y) {
		for (int x = 0; x < num; ++x) {
			if (map[y][x] == '1' &&visit[y][x] == false) 
			{
				mapCount = 1;
				dfs(x, y);
				vec_mapCount.push_back(mapCount);
			}
		}
	}

	sort(vec_mapCount.begin(), vec_mapCount.end());
	
	cout << vec_mapCount.size()<<endl;
	for (int i = 0; i < vec_mapCount.size(); ++i) 
	{
		cout << vec_mapCount[i] << endl;
	}

}












//int main()
//{
//	cin >> num;
//
//	for (int y = 0; y < num; ++y) 
//	{
//			cin >> map[y];
//	}
//
//	for (int x = 0; x < num; ++x)
//	{
//		for (int y = 0; y < num; ++y) 
//		{
//
//			if (map[y][x] == '1') 
//			{
//				q.push({ {y,x},1 });
//				map[y][x] = '0';
//				int maxcount = 0;
//				while (!q.empty()) 
//				{
//					int ddy = q.front().first.first;
//					int ddx = q.front().first.second;
//					int ddcount = q.front().second;
//					q.pop();
//					for (int i = 0; i < 4; ++i) 
//					{
//						int chx = ddx + dx[i];
//						int chy = ddy + dy[i];
//						if (chx < num && chx > -1 && chy >-1 && chy < num)
//						{
//							if(map[chy][chx]=='1'){
//								map[chy][chx] = '0';
//								q.push({ {chy,chx},ddcount + 1 });
//								if (maxcount < ddcount + 1)
//									maxcount = ddcount + 1;
//							}
//						}
//
//					}
//				}
//				if(maxcount!=0)
//					vec_mapCount.push_back(maxcount);
//			}
//		}
//	}
//
//
//	sort(vec_mapCount.begin(), vec_mapCount.end());
//
//	cout << vec_mapCount.size()<<endl;
//	for (int i = 0; i < vec_mapCount.size(); ++i) 
//	{
//		cout << vec_mapCount[i] << endl;
//	}
//
//}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
