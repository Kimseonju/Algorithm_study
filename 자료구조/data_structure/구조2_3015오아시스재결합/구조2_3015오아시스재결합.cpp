#include <iostream>
#include <stack>
#include <memory.h>
using namespace std;
int N;

int member[5000001];
int main()
{
	cin >> N;
	stack<pair<int,int>> st;
	long long ans = 0;


	for (int i = 0; i < N; ++i)
	{
		cin >> member[i];
	}
	for (int i = 0; i < N; ++i)
	{
		pair<int, int> p = { member[i], 1 };

		while(!st.empty())
		{
			if (member[i] > st.top().first)
			{
				ans+= st.top().second;
				st.pop();
			}
			else if (member[i] == st.top().first)
			{
				ans += st.top().second;
				p.second += st.top().second;
				st.pop();
			}
			else
			{
				ans++;
				break;
			}
				
		}
		st.push(p);
	}

	cout << ans;

}
