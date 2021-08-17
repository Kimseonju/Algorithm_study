
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
int main()
{
	oneoneoneone();
	cin >> N >> M;
	map<string, int> stringmap;
	int ans = 0;
	for (size_t i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		stringmap.insert({ str,i });
	}
	for (size_t i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (stringmap.find(str) != stringmap.end())
		{
			ans++;
		}
	}
	cout << ans;
}
