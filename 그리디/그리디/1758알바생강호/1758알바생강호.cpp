#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool aaa(int x, int y)
{
	return x > y;
}
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end(), aaa);
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += max(0,a[i] - ((i + 1) - 1));
	}
	cout << ans;
}
