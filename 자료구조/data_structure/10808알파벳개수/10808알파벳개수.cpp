#include <iostream>
using namespace std;

#include <string>
#include <memory.h>
int main()
{
	string str;
	cin >> str;
	int num[26] = {-1};

	memset(num, -1, sizeof(int)*26);

	for (int i = 0; i < str.size(); ++i)
	{
		if(num[str[i] - 97]==-1)
			num[str[i] - 97]=i;
	}
	for (int i = 0; i < 26; ++i)
	{
		cout << num[i] << " ";
	}
}
