#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


//N이 세로 M이 가로
int N, M;
int ans = 2147483647;

//x로 셀때
int Gr;
int Br;
//y로 셀때
int Gc;
int Bc;
int main()
{
	cin >> N >> M;

	vector<string> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < M; ++j)
		{
			if (a[i][j]&1)
			{
				cnt++;
			}
		}
		if (cnt%2==0)
		{
			Gr += 1;
		}
		else
		{
			Br += 1;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < N; ++j)
		{
			if (a[i][j] & 1)
			{
				cnt++;
			}
		}
		if (cnt % 2 == 0)
		{
			Gc += 1;
		}
		else
		{
			Bc += 1;
		}
	}
	
	int temp1 = Br;
	if (Br % 2 == 0)
		temp1 += Bc;
	else
		temp1 += Gc;

	int temp2 = Gr;
	if (Gr % 2 == 0)
		temp2 += Bc;
	else
		temp2 += Gc;

	int ans = min(temp1, temp2);
	cout << ans << '\n';
}