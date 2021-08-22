
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
void oneoneoneone()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int treelength = 0;
int branchlength = 0;
int refnode = -1;


int N, R;
vector<pair<int, int>>node[200001];
int branchlengthCheck(int nodenum, int length)
{
	if (node[nodenum].size() == 0)
		return length;
	int checklength = length;
	for (int i = 0; i < node[nodenum].size(); ++i)
	{
		int templength=branchlengthCheck(node[nodenum][i].first, node[nodenum][i].second+length);
		if (checklength < templength)
			checklength = templength;
	}
	return checklength;
}
void bfs(int nodenum, int prevnode)
{
	if (node[nodenum].size() == 0)
		return;

	if (node[nodenum].size() <= 1 && refnode==-1)
	{
		treelength += node[nodenum][0].second;

		int nextnode = node[nodenum][0].first;
		bfs(nextnode, nodenum);

	}
	else 
	{
		refnode = nodenum;
		int checklength = 0;
		for (int i = 0; i < node[nodenum].size(); ++i)
		{
			int templength=branchlengthCheck(node[nodenum][i].first, node[nodenum][i].second);
			if (checklength < templength)
				checklength = templength;
		}

		branchlength = checklength;
	}

}

int main()
{
	oneoneoneone();

	cin >> N >> R;

	for (int i = 1; i < N; ++i)
	{
		int start, end, num;
		cin >> start >> end >> num;
		node[start].push_back(make_pair(end, num));
		//node[end].push_back(make_pair(start, num));

	}

	bfs(R, 0);
	cout << treelength << " " << branchlength;

}
