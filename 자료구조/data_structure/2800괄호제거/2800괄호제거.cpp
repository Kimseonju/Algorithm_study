#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int count1 = 0;
string strtext;

int match[200];
vector<int> v;
vector<string> vstr;


void sol(int num, stack<int> st, string solstr, int del)
{
	if (strtext.size() == num)
	{
		if (st.empty() && del!=0)
		{
			vstr.push_back( solstr);
		}
		return;
	}

	solstr.push_back(strtext[num]);
	sol(num + 1, st, solstr, del);

	if (strtext[num] == '(')
	{
		count1++;
		st.push(num);
		solstr.pop_back();
		sol(num + 1, st, solstr, del);
	}
	else if (strtext[num] == ')')
	{
		if (!st.empty())
		{
			if (num == match[st.top()])
			{
				del++;
				st.pop();
				solstr.pop_back();
				sol(num + 1, st, solstr, del);
			}
			else
				return;
		}
		else
		{
			return;
		}
	}
}

int main()
{
	cin >> strtext;

	stack<int> s;
	for (int i = 0; i < strtext.size(); i++)
	{
		if (strtext[i] == '(')
			s.push(i);

		else if (strtext[i] == ')')
		{
			int match_front = s.top();

			match[match_front] = i; 

			s.pop();
		}
	}

	stack<int> st;
	string str = "";



	sol(0, st, str, 0);

	sort(vstr.begin(), vstr.end());
	vstr.erase(unique(vstr.begin(), vstr.end()), vstr.end());
	for (int i = 0; i < vstr.size(); ++i)
	{
		cout << vstr[i] << '\n';
	}
}