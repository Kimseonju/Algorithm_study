
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
int N;
int main()
{
	oneoneoneone();
	priority_queue<long long> pq;
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			long long num;
			cin >> num;

			if (pq.size() < N)
				pq.push(-num);
			else
			{
				long long n=-pq.top();
				if (n < num)
				{
					pq.pop();
					pq.push(-num);
				}
			}
		}

	}

	cout << -pq.top();
}
