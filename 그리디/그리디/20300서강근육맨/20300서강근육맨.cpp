#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;


int main()
{
	int n;
	cin >> n;

	vector<ll> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	//짝수일때
	ll ans = 0;
	if (n % 2 == 1)
	{
		ans = v[n - 1];
		for (int i = 0; i < n / 2; ++i)
		{
			ans = max(ans, v[i] + v[n-2 - i]);
		}
	}
	else
	{
		ans = v[0]+v[n - 1];
		for (int i = 0; i < n / 2; ++i)
		{
			ans = max(ans, v[i] + v[n - 1 - i]);
		}
	}
	cout << ans;

}
