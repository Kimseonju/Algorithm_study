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
int N, M;
map<int, int> problemmap;
map<int, map<int, int>> level_map;
int main()
{
	oneoneoneone();
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int num, level;
		cin >> num >> level;
		problemmap.insert({ num,level });
		if (level_map.find(level) == level_map.end())
		{
			map<int, int>mmap;
			mmap.insert({ num,0 });
			level_map.insert({ level, mmap });
		}
		else
		{
			level_map.find(level)->second.insert({ num,0 });
		}
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
				auto iter = (--level_map.end())->second.end();
				iter--;
				cout << iter->first << '\n';
			}
			else if (one == -1)
			{
				cout << level_map.begin()->second.begin()->first << '\n';
			}
		}
		else if (str == "solved")
		{

			int num;
			cin >> num;
			auto iter = problemmap.find(num);

			auto& veciter = level_map.find(iter->second)->second;
			auto veciterbegin = veciter.begin();
			auto veciterend = veciter.end();
			for (; veciterbegin != veciterend; veciterbegin++)
			{
				if (veciterbegin->first == num) {
					veciter.erase(veciterbegin);
					break;
				}
			}
			if (veciter.empty())
				level_map.erase(level_map.find(iter->second));
			problemmap.erase(problemmap.find(num));


		}
		else if (str == "add")
		{
			int num, level;
			cin >> num >> level;
			problemmap.insert({ num,level });
			if (level_map.find(level) == level_map.end())
			{
				map<int, int>mmap;
				mmap.insert({ num,0 });
				level_map.insert({ level, mmap });
			}
			else
			{
				level_map.find(level)->second.insert({ num,0 });
			}
		}
	}
}