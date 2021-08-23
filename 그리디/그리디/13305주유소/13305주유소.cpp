// 13305주유소.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<ll>length(n);
	vector<ll>node(n+1);

	for (int i = 0; i < n-1; ++i)
	{
		cin >> length[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> node[i];
	}
	//제일 적은 주유소로 적은가격에 도착하는것이 관건
	ll coin=0;
	ll liter = node[0];
	
	for (int i = 0; i < n; ++i)
	{
		if (node[i] < liter)
			liter = node[i];
		coin += liter * length[i];
	}
	cout << coin;
}