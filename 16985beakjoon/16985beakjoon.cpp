// 16985beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;
int board[5][5][5];

bool visited[5][5][5];
int ans = 999999999; 
int dx[] = { 0, 1, 0, -1, 0, 0 }, dy[] = { -1, 0, 1, 0, 0, 0 }, dz[] = { 0, 0, 0, 0, 1, -1 };

int n = 5;
void rotate_board(int idx) {

	int tmp[5][5];
	memcpy(tmp, board[idx], sizeof(tmp));
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++)
		{
			board[idx][i][j] = tmp[n - 1 - j][i];
		}
	}
}
struct Point {
	int x, y, z, i;
	Point(int ax, int ay, int az, int ai)
	{
		x = ax;
		y = ay;
		z = az;
		i = ai;
	}
};
int bfs()
{
	memset(visited, false, sizeof(visited));

}

int main()
{
	for (int k = 0; k < 5; ++k)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				cin >> board[k][i][j];
			}
		}
	}


	for (int a = 0; a < 4; ++a)
	{
		rotate_board(0); 
		if (!board[0][0][0])
			continue;
		for (int b = 0; b < 4; ++b)
		{
			rotate_board(1);
			for (int c = 0; c < 4; ++c)
			{
				rotate_board(2);

				for (int d = 0; d < 4; ++d)
				{

					rotate_board(3);
					for (int d = 0; d < 4; ++d)
					{
						rotate_board(4); 
						ans = min(ans, bfs()); 
					}
				}
			}
		}
	}
	cout << ans << '\n';


}