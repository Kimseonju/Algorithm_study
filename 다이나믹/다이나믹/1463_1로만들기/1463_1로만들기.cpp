

#include <iostream>
using namespace std;
int d[1000005];
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= n; ++i)
	{
		d[i]= 1000007;
	}
	for (int i=4; i<=n; ++i)
	{
		int x3 = 1000007;
		int x2 = 1000007;
		int x1 = 1000007;
		if(i%2==0)
			x2 = d[i / 2] + 1;
		if(i%3==0)
			x3 = d[i / 3] + 1;
		
		x1 = d[i - 1] + 1;
		
		int b = min(x1, x2);
		b = min(b, x3);

		d[i] = b;
	}
	cout << d[n];
}