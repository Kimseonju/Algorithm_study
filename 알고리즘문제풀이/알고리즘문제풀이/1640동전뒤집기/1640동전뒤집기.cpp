#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


//N이 세로 M이 가로
int N, M;
int ans = 2147483647;

//x로 셀때
bool x[1000];
//y로 셀때
bool y[1000];
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); ++j)
		{
			if (str[j]&1)
			{
				x[i] = !x[i];
				y[j] = !x[j];
			}
		}
	}

	int countx=0, county = 0;
	for (int i = 0; i < N; i++) 
		countx += x[i] % 2;
	for (int i = 0; i < M; i++) 
		county += y[i] % 2;

	int N1, M1;
	N1 = N % 2;
	M1 = M % 2;
	int countx1 = countx % 2;
	int county2 = county % 2;
	if (N1 == 0 && M1 == 0)
	{
		if (countx1 == 1) {
			cout << "-1";
			return 0;
		}
	}
	else if (N1 != 0 && M1 == 0)
	{

	}
	else if (N1 == 0 && M1 != 0)
	{

	}
	else
	{

	}

	int b = 0;

}