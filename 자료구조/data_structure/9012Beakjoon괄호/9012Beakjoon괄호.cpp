#include <iostream>
#include <string>
#include <stack>
using namespace std;
int N;
int Left, Right;

bool stackCheck(const string& str)
{
	int len = str.size();
	stack<char>st;

	for (int i = 0; i < len; ++i)
	{
		char c = str[i];
		if ('(' == c)
		{
			st.push(c);
		}
		else
		{
			if (!st.empty())
			{
				st.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return st.empty();
}
int main()
{
	string str;
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		if (stackCheck(str)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}

}
