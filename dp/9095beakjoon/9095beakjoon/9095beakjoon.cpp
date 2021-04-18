#include <iostream>
#include <vector>
using namespace std;

int d[12];

int dp(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (x == 3) return 4;
	if (d[x] != 0) return d[x];
	return d[x] = (dp(x - 1) + dp(x - 2) + dp(x - 3));
}
int main(void)
{
	int a, b;
	vector<int> c;
	cin >> a;
	for (int i = 0; i < a; ++i)
	{
		cin >> b;
		c.push_back(b);
	}
	for (int i = 0; i < a; ++i)
	{
		cout << dp(c[i]) << endl;
	}
}