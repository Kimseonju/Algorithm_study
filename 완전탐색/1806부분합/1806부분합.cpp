#include <iostream>
#include <queue>
#include <memory.h>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
int main()
{
	cin >> n >> m;

	vector<int> v(n);
	
	for(int i=0; i<n; ++i)
		cin >> v[i];
	int ans = 200000;
	int left = 0, right = 0;
	int sum =v[0];


	while (left<=right && right < v.size())
	{
		if (sum < m)
		{
			right += 1;
			if (right >= v.size())
			{
				continue;
			}
			sum += v[right];
		}
		else if (sum == m)
		{
			int checknum = right - left+1;
			if (ans > checknum)
				ans = checknum;

			right += 1;
			if (right >= v.size())
			{
				continue;
			}
			sum += v[right];
		}
		else
		{
			int checknum = right - left + 1;
			if (ans > checknum)
				ans = checknum;

			sum -= v[left];
			left += 1;

		}
		
	}

	if (ans > n) 
		ans = 0;

	cout << ans << endl;


}