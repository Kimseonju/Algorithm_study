
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
void oneoneoneone()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

int main()
{
	oneoneoneone();
	priority_queue<pair<int, int>> pq;
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int c;

		cin >> c;

		if (c != 0)
		{
			if (c > 0)
			{
				pq.push(make_pair(-c, -1));
			}
			else
				pq.push(make_pair(c, 1));
		}
		else
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				int cb=pq.top().first;
				cb*=pq.top().second;
				cout << cb<<'\n';
				pq.pop();
			}
		}
	}


}
