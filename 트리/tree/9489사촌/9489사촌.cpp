
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
void oneoneoneone()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
int nodedepth[1000001];
int parent[1000001];

bool IsSibling(int start, int end)
{
	int parentstart = parent[start];
	int parentend = parent[end];
	if (parentstart == parentend)
		return false;

	return parent[parentstart] == parent[parentend];
}
int main()
{
	oneoneoneone();
	int n, k;

	vector<int>node[1002];
	for (;;)
	{
		cin >> n >> k;

		if (n == 0 && k == 0)
			break;
		int checknum = -1;
		int num;
		int depth = 1;
		//첫루트 카운트 1
		int prevdepthcount = 0;

		
		memset(nodedepth, 0, sizeof(nodedepth));
		for (int i = 0; i < n; ++i)
		{
			node[i].clear();
		}
		cin >> num;
		node[depth].push_back(num);
		checknum = num;
		parent[num] = num;

		for (int i = 0; i < n-1; ++i)
		{
			cin >> num;

			if (num - checknum > 1)
			{
				prevdepthcount++;
				if (prevdepthcount >= node[depth-1].size())
				{
					depth++;
					prevdepthcount = 0;
				}

			}
			node[depth].push_back(num);
			nodedepth[num] = depth;
			checknum = num;
			parent[num] = node[depth - 1][prevdepthcount];
		}
		int depth_K=nodedepth[k];
		int ans = 0;
		for (int i = 0; i < node[depth_K].size(); ++i)
		{
			if (k == node[depth_K][i])
				continue;
			if (IsSibling(k, node[depth_K][i]))
				ans++;
		}

		cout << ans << '\n';

	}
}
