
#include <iostream>
#include <string>
#include <stack>


using namespace std;
int main()
{
	string str;
	stack<int> st;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if ('(' == str[i])
		{
			st.push(i);
		}
		else
		{
			if (1 == i-st.top())//레이저
			{
				//레이저 (삭제
				st.pop();
				//남은선 자르는거니 플
				ans += st.size();
			}
			else//선의 끝
			{
				st.pop();
				ans += 1;
			}
		}
	}
	cout << ans;
}
