
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;

	while (getline(cin, str)) {
		int num[4] = { 0 };
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				++num[0];
			}
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				++num[1];
			}
			if (str[i] >= '0' && str[i] <= '9')
			{
				++num[2];
			}
			if (str[i] == ' ')
			{
				++num[3];
			}

		}
		for (int i = 0; i < 4; ++i)
		{
			cout << num[i] << " ";
		}
	}

}
