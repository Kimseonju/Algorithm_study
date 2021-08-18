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
int N, M;
priority_queue<pair<int, int>>minq , maxq;
map<int, int> deletenum;
int main()
{
	oneoneoneone();
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int num, level;
		cin >> num >> level;
		maxq.push(make_pair(level, num));
		minq.push(make_pair(-level, -num));
	}

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		string str;
		cin >> str;
		if (str == "recommend")
		{
			int one;
			cin >> one;
			if (one == 1)
			{
				for (;;)
				{

					int level = maxq.top().first;
					int num = maxq.top().second;
					
					auto finditer = deletenum.find(num);
					if (finditer == deletenum.end())
					{
						cout << num << '\n';
						break;
					}
					else
					{
						finditer->second++;
						if (finditer->second == 2)
							deletenum.erase(finditer);
						maxq.pop();
					}
				}


			}
			else if (one == -1)
			{
				for (;;)
				{

					int level = -minq.top().first;
					int num = -minq.top().second;
					auto finditer = deletenum.find(num);
					if (finditer == deletenum.end())
					{
						cout << num << '\n';
						break;
					}
					else
					{
						finditer->second++;
						if (finditer->second == 2)
							deletenum.erase(finditer);
						minq.pop();
					}
				}
			}
		}
		else if (str == "solved")
		{

			int num;
			cin >> num;
			deletenum.insert({ num,0 });



		}
		else if (str == "add")
		{
			int num, level;
			cin >> num >> level;
			minq.push(make_pair(-level, -num));
			maxq.push(make_pair(level, num));
		}
	}
}