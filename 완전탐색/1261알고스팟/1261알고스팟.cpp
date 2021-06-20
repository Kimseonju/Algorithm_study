
#include <iostream>
#include <deque>
#include <memory.h>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%1d", &map[i][j]);
		}
	}
}
