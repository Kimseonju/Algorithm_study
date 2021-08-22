#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>>node[20];
bool dist[20];
int cnt1 = 0;
bool dfs(int nodenum, int cnt)
{
	bool check = false;
	for (int i = 0; i < node[nodenum].size(); ++i)
	{
		int nextnode = node[nodenum][i].first;
		if (dist[nextnode])
			continue;
		check = true;
		bool loopcheck = true;
		dist[nextnode] = true;
		node[nodenum][i].second = 1;
		dfs(nextnode, cnt+1);
		
	}
	cnt1++;
	return check;

}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (size_t j = 0; j < str.size(); j++)
		{
			if (str[j] == '1')
			{
				node[i].push_back(make_pair(j,0));
			}
		}
	}
	dist[0] = true;
	dfs(0, 0);



	cout << cnt1 + 1 << '\n';
}
