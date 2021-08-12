#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N;
stack<int> st;
vector<int> vst;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> N;
	int input;
	string str;
	bool check = false;
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> input;
		while (!st.empty())
		{
			int temp = st.top();
			if (temp >= input)
			{
				break;
			}
			else
			{
				st.pop();
				vst.pop_back();
				cnt++;
			}

		}

		if (st.empty())
		{
			str += "0 ";
		}
			
		else
		{
			check = true;
			str += to_string(vst.back()) + " ";
		}
		st.push(input);
		vst.push_back(i);
	}
	if (check)
		cout << str;
	else
		cout << "0";
	return 0;
}