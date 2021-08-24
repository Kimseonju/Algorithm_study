

#include <iostream>
using namespace std;
int d[100];


int dp(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (x == 3)return 4;
	if(d[x]!=0) return d[x];
	return d[x] = dp(x - 1) + dp(x - 2) + dp(x - 3);
}
int main()
{

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		cout <<dp(n)<<'\n';


	}

}