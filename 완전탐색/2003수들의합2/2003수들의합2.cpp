#include <iostream>
#include <queue>
#include <memory.h>
#include <string>
#include <algorithm>
using namespace std;


int n, m;
//이 방법이 아니라 포인터로 푼느게 정ㄷ바임
//Left Right 더하면서 값이 커지면 left에있는것을 당기면서 푸는것
int main()
{
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	int ans = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			int sum = 0;
			for (int j = i; j < v.size(); ++j)
			{
				sum += v[j];
				if (sum == m)
				{
					ans++;
					break;
				}
			}
		}

	cout << ans << endl;
}
