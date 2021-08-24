

#include <iostream>
using namespace std;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int d[60000];
int s[60000];
int main()
{
	init();

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; ++i)
	{
		s[i] = -1;
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		s[i] = s[i] % 2;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int cnt = 0;
		if (s[i] % 2 == 0)
		{
			cnt++;
			int kcnt = 0;
			for (int j = i + 1; j <= n; ++j)
			{
				if (s[j] % 2 == 0)
					cnt++;
				else
				{
					kcnt++;
					if (kcnt > k)
						break;
				}

			}

		}

		d[i] = cnt;
		ans = max(ans, d[i]);
	}
	cout << ans;

}