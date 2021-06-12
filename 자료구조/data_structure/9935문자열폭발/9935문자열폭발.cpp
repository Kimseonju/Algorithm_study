#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
	string str;
	string Target;

	deque<char> dqL;
	cin >> str >> Target;
	bool find = true;
	for (int i = 0; i < str.size(); ++i)
	{
		dqL.push_back(str[i]);
		if (dqL.size() >= Target.size())
		{
			for (int k = 0; k < Target.size(); ++k)
			{
				if (dqL[dqL.size() - Target.size() + k] != Target[k])
				{
					find = false;
					break;
				}
			}

			if (find)
			{
				for (int i = 0; i < Target.size(); i++)
					dqL.pop_back();
			}
			find = true;
		}
	}

	str = "";
	for (int i = 0; i < dqL.size(); i++)
		str.push_back(dqL[i]);

	if (str.size() == 0)
	{
		cout << "FRULA";
	}
	else
	{
		cout << str;
	}
	
}