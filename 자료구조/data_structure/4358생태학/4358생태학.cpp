
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	map<string, int> stringmap;
	int cnt = 0;
	while (true) {
		string str;
		getline(cin, str, '\n');
		if (cin.eof() == true) break;
		cnt++;
		auto iter=stringmap.find(str);
		if (iter == stringmap.end())
		{
			stringmap.insert({ str,1 });
		}
		else
		{
			iter->second++;
		}

	}
	cout << fixed;
	cout.precision(4);
	auto iter = stringmap.begin();
	auto iterEnd = stringmap.end();
	for (; iter != iterEnd; ++iter)
	{
		float ans = float(iter->second) / float(cnt)* 100;
		cout << iter->first << ' ' << ans << '\n';
	}
	
}
