// 2138전구와스위치.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;
string	Nbulb;

string Fbulb;
int n;
void turnonoff(char& c)
{
	if (c == '0')
		c = '1';
	else
		c = '0';
}
void first(string& nbulb)
{
	turnonoff(nbulb[0]);
	turnonoff(nbulb[1]);
}
void se(string& nbulb ,int i)
{
	turnonoff(nbulb[i-1]);
	turnonoff(nbulb[i]);
	turnonoff(nbulb[i+1]);
}
void last(string& nbulb)
{
	turnonoff(nbulb[n-2]);
	turnonoff(nbulb[n-1]);
}
int main()
{
	cin >> n;
	cin >> Nbulb;
	cin >> Fbulb;


	int cnt = 0;
	string nbulb = Nbulb;

	for (int i = 1; i < n-1; ++i)
	{
		if (Fbulb[i - 1] != nbulb[i - 1])
		{
			se(nbulb, i);
			cnt++;
		}
	}
	if (nbulb == Fbulb)
	{
		cout << cnt;
		return 0;
	}
	else
	{
		last(nbulb);
		cnt++;
		if (nbulb == Fbulb)
		{
			cout << cnt;
			return 0;
		}
	}


	cnt = 0;
	nbulb = Nbulb;

	first(nbulb);
	cnt++;
	for (int i = 1; i < n - 1; ++i)
	{
		if (Fbulb[i - 1] != nbulb[i - 1])
		{
			se(nbulb, i);
			cnt++;
		}
	}
	if (nbulb == Fbulb)
	{
		cout << cnt;
		return 0;
	}
	else
	{
		last(nbulb);
		cnt++;
		if (nbulb == Fbulb)
		{
			cout << cnt;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}
