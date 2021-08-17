
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
int T;
int K;
int main()
{
	oneoneoneone();
	cin >> T;


	for (int i = 0; i < T; ++i)
	{
		multimap<int, int> pq;
		cin >> K;
		for (size_t j = 0; j < K; j++)
		{
			char ch;
			cin >> ch;
			int n;
			cin >> n;
			if (ch == 'D')
			{
				//최대값
				if (pq.empty())
					continue;
				if (n == 1)
				{
					pq.erase(--pq.end());
				}
				//최솟값
				else if (n == -1)
				{
					pq.erase(pq.begin());
				}
			}
			else if (ch == 'I')
			{
				pq.insert(make_pair(n,i));
			}
		}

		if (pq.empty())
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << (--pq.end())->first << ' ' << pq.begin()->first << '\n';
		}


	}



}
