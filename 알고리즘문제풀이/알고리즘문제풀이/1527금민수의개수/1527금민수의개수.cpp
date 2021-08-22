#include <iostream>
using namespace std;

long long a;
long long b;
int cnt = 0;

void sol(long long num)
{
	if (b < num)
		return;
	if (a <= num && num <= b)
		cnt++;
	sol(num * 10 + 4);
	sol(num * 10 + 7);
}


int main()
{
	cin >> a;
	cin >> b;
	
	sol(4);
	sol(7);
		
	cout << cnt;
}