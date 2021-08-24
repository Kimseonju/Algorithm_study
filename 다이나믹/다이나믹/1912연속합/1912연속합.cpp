

#include <iostream>
using namespace std;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int s[100015];
int d[100015];
int main()
{
	init();
	int n;
	cin >> n;

	fill_n(s, n+10, -1005);

	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
	}
	d[1] = s[1];
	int ans = d[1];
	for (int i = 2; i <= n; ++i)
	{
		if (d[i - 1] < s[i])
		{
			if(d[i-1]<0)
				d[i] = s[i];
			else
				d[i] = d[i - 1]+s[i];
		}
			
		else
			d[i] = d[i - 1] + s[i];
		ans = max(ans, d[i]);
	}
	cout << ans;
}