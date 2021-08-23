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

	vector<int> v(n+1);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), aaa);
	int ans = 0;
	int cnt = 1;
	for (int i = 0; i < n; ++i)
	{
		if (cnt % 3 == 0)
		{
			cnt++;
			continue;
		}
		ans += v[i];
		cnt++;
	}
	cout << ans;
}
