#include <iostream>
#include <deque>
using namespace std;
deque<pair<int, int>> deq;
bool check[1000];
int main()
{
	int N;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		deq.push_back(make_pair(a,i));
	}
	
	int data = 0;
	int countt = 0;
	auto iter = deq.begin();
	auto iterEnd = deq.end();
	
	int allcount = 0;
	while (true)
	{
		if (allcount == N)
			break;
		if (data > 0)
		{
			++iter;
			if (iter == iterEnd)
			{
				iter = deq.begin();
			}
			if(!check[(*iter).second])
				data--;
		}
		else if (data < 0)
		{
			if (iter == deq.begin())
			{
				iter = deq.end();
			}
			--iter;
			if (!check[(*iter).second])
				data++;
		}
		else
		{
			data=(*iter).first;
			countt= (*iter).second;
			check[countt] = true;
			cout << countt + 1 << ' ';
			allcount++;
		}

	}

}
