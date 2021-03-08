// 16998beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[21][21];
int visit[21][21];
struct pos {
	int x, y;
	pos(int ax, int ay)
	{
		x = ax;
		y = ay;
	}
};
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> map[i][j];
		}
	}
	queue<pos>q;

	

	//섬생성(필드)
	//

    
}
