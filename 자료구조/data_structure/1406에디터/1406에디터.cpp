
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int N;
int main()
{
	stack<char> st;
	stack<char> stR;
	string str;
	char PKKK;
	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		st.push(str[i]);
	}

	cin >> N;
	char ans;
	for (int i = 0; i < N; ++i)
	{
		cin >> ans;
		if (ans == 'L')
		{
			if (st.empty())
				continue;
			stR.push(st.top());
			st.pop();
		}
		if (ans == 'D')
		{
			if (stR.empty())
				continue;
			st.push(stR.top());
			stR.pop();
		}
		if (ans == 'B')
		{
			if (st.empty())
				continue;
			st.pop();
		}
		if (ans == 'P')
		{
			cin >> PKKK;
			st.push(PKKK);
		}
	}
	while (!st.empty()) {
		stR.push(st.top());
		st.pop();
	}
	while (!stR.empty()) {
		cout << stR.top();
		stR.pop();
	}


}
