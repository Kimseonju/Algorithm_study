#include <iostream>
using namespace std;
#include <string>
int main()
{
	string str;
	string ansstr;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'X')
			cnt++;
		if (str[i] == '.')
		{
			if (cnt % 2 == 1)
			{
				cout << "-1";
				return 0;
			}
			if (cnt == 2)
			{
				for (int j = 0; j < cnt; ++j)
				{
					str[i - j-1] = 'B';
				}
				cnt = 0;
			}
		}
		if (cnt == 4)
		{
			for (int j = 0; j < cnt; ++j)
			{
				str[i - j] = 'A';
			}
			cnt = 0;
		}
	}

	if (cnt == 2)
	{
		int size=str.size();
		for (int j = 0; j < cnt; ++j)
		{
			str[size - j-1] = 'B';
		}
		cnt = 0;
	}
	if (cnt % 2 == 1)
	{
		cout << "-1";
		return 0;
	}
	cout << str;
	return 0;
}
