
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
	cin.tie(nullptr);
	cout.tie(nullptr);
}
int N;
int W;
vector<int>node[500001];
int main()
{
	cin >> N >> W;
	for (int i = 1; i < N; ++i)
	{
		int start, end;
		cin >> start >> end;
		node[start].push_back(end);
		node[end].push_back(start);
	}
	int cnt = 0;
	//러프노드 
	for (int i = 2; i <= N; ++i)
	{
		if (node[i].size() == 1)
			cnt++;
	}
	cout << fixed;
	cout.precision(6);
	double ans = W /(double)cnt;
	cout << ans<<'\n';
}
