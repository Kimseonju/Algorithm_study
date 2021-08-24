
#include <iostream>
using namespace std;
int d[5001];
int num[2];
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i <= n; i+=3)
	{
		for (int j = 0; j <= n; j += 5)
		{
			if (i + j == n)
			{
				d[i / 3 + j / 5] = 1;
			}
		}
	}

	for (int i = 0; i <= n; ++i)
	{
		if (d[i] == 1)
		{
			cout << i;
			return 0;
		}
	}

	cout << "-1";
	return 0;

}