

#include <iostream>
using namespace std;
int stairs[303];
int d[303];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> stairs[i];
	}

	int cnt = 0;
	d[1] = stairs[1];
	d[2] = stairs[1] + stairs[2];
	d[3] = max(stairs[1]+stairs[3], stairs[2] + stairs[3]);
	for (int i = 4; i <=n ; ++i)
	{
		d[i] = max(d[i-3]+stairs[i-1]+stairs[i], d[i - 2] + stairs[i]);
	}
	cout << d[n];

}