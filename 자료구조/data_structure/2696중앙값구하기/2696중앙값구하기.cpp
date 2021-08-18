
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
void oneoneoneone()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
int T, M;

int main()
{
	oneoneoneone();
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> M;
		int middlenum = 0;
		int cnt = 0;

		priority_queue<int>minq, maxq;
		vector<int> ans;
		cin >> middlenum;
		ans.push_back(middlenum);
		for (size_t j = 2; j <= M; j++)
		{
			int num;
			cin >> num;
			if (num < middlenum)
			{
				maxq.push(num);
			}
			else
			{
				minq.push(-num);
			}
			if (j % 2 == 1)
			{ //홀수 번째 수를 읽을 때 마다
				int maxq_size = maxq.size();
				int minq_size = minq.size();
				if (maxq_size < minq_size)
				{
					maxq.push(middlenum);
					maxq_size++;
				}
				else
				{
					minq.push(-middlenum);
					minq_size++;
				}

				if (maxq_size > minq_size)
				{ // 힙 중에 사이즈가 큰 힙의 top이 mid가 됨
					middlenum = maxq.top();
					maxq.pop();
				}
				else
				{
					middlenum = -minq.top();
					minq.pop();
				}
				ans.push_back(middlenum);
			}
		}
		cout << ans.size() << '\n';
		for (size_t j = 1; j <= ans.size(); j++)
		{

			cout << ans[j-1] << ' ';
			if (j % 10 == 0)
				cout << '\n';
		}
		cout << '\n';

	}
	

	
	


}