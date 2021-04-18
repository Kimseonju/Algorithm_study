#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int n, m;
int dpp[1001];
int dp(int a)
{
	if (a == 1)
		return 1;
	if (a == 2)
		return 2;
	if (dpp[a] != 0)
		return dpp[a];
	dpp[a] = dp(a - 1) + dp(a - 2);
	dpp[a] = dpp[a] % 10007;
	return dpp[a];
}

int main(void)
{
	cin >> n;
	cout << dp(n);
}