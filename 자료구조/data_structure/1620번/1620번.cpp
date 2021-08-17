
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
	map<string, int> stringmap;
	map<int, string> intmap;
	oneoneoneone();
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		string str;
		cin >> str;
		stringmap.insert({ str, i });
		intmap.insert({ i, str });
	}
	for (int i = 0; i < M; ++i)
	{
		string str;
		cin >> str;
		//문자열
		if (str[0] - 'A' >=0)
		{
			cout << stringmap.find(str)->second<<'\n';
		}
		else
		{
			cout << intmap.find(atoi(str.c_str()))->second<<'\n';
		}
	}
}