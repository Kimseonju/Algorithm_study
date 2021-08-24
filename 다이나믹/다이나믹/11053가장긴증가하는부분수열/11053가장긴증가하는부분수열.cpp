

#include <iostream>
using namespace std;
void init() 
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int A[1050];
int d[1050];

int main()
{
	init();
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}
	int ans = 1;
	fill_n(d, 1050, 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j) {
			{
				if (A[i] > A[j])
				{
					d[i] = max(d[i], d[j] + 1);


				}
			}
			ans = max(ans, d[i]);
		}

	}
	cout << ans;
}