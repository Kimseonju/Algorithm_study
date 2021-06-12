#include <iostream>
#include <stack>
#include <string>
using namespace std;
int N;

int main()
{
	stack<int> st;
	string str;
	cin >> N;
	int ans;
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> ans;
			st.push(ans);
		}
		if (str == "pop")
		{
			if (!st.empty())
			{
				cout << st.top() << endl;
				st.pop();
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		if (str == "size")
		{
			cout << st.size() << endl;
		}
		if (str == "empty")
		{
			if (st.empty())
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
		if (str == "top")
		{
			if (!st.empty()) {
				cout << st.top() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
	}
}
