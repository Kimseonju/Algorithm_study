#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
vector<int> a;
void gen(long long x) {
	if (x >= 1000000) 
		return;
	if (x > 0) {
		a.push_back(x);
	}
	gen(x * 10 + 4);
	gen(x * 10 + 7);
}

int dp[10000001];
int v[1000001];
int main()
{
	cin >> n;
	gen(0);

	sort(a.begin(), a.end());

	for (int i = 1; i <= n; ++i)
	{
		for (int x : a)
		{
			if (i - x < 0)
				continue;
			if (dp[i - x] == -1)
				continue;
			if (dp[i] == -1 || dp[i] > dp[i - x] + 1)
			{
				dp[i] = dp[i - x] + 1;
				v[i] = x;
			}
		}
	}
	if (dp[n] == -1) {
		cout << -1 << '\n';
		return 0;
	}
	vector<int> ans;
	while (n > 0) {
		ans.push_back(v[n]);
		n = n - v[n];
	}
	sort(ans.begin(), ans.end());
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0;

}