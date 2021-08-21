
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;


int parent[100001];
int depth[100001];
int findParent(int x)
{
	if (x == parent[x])
		return x;
	else
	{
		int temp= findParent(parent[x]);
		return temp;
	}
}
int findDepth(int x)
{
	int cnt = 0;
	if (depth[x] != -1)
		return depth[x];
	int checknum = x;
	for (;;)
	{
		if (parent[checknum] != checknum)
		{
			cnt++;
			checknum = parent[checknum];
		}
		else
		{
			depth[x] = cnt;
			return cnt;
		}
	}
}

int unionParent(int x, int y)
{
	if (findDepth(x) > findDepth(y))
	{
		return unionParent(parent[x], y);
	}
	else if(findDepth(x) < findDepth(y))
	{
		return unionParent(x, parent[y]);
	}
	else
	{
		if (x == y)
			return x;
		else if (parent[x] == parent[y])
			return parent[x];
		else
			return unionParent(parent[x], parent[y]);
	}
}

void oneoneoneone()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int T;
int nodecount;
int main()
{
	oneoneoneone();
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> nodecount;
		memset(depth, -1, sizeof(depth));
		for (size_t j = 1; j <= nodecount; j++)
		{
			parent[j] = j;
		}
		for (size_t j = 0; j < nodecount-1; j++)
		{
			int start, end;
			cin >> start >> end;
			parent[end] = start;
		}
		int start, end;
		cin >> start >> end;
		int ans=unionParent(start, end);
		cout << ans << '\n';
	}
}
