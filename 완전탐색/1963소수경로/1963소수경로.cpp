#include <iostream>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;
bool check[10001];
int d[10001];
bool Eratos[10001];
int change(int start, int index, int num)
{
	if (index == 0 && num == 0) 
		return -1;
	string s = to_string(start);
	s[index] = num + '0';
	return stoi(s);
}
int main()
{

	for (int i = 2; i <= 10000; i++)
		Eratos[i] = true;
	for (int i = 2; i * i <= 10000; i++)
	{
		if (Eratos[i])
			for (int j = i * i; j <= 10000; j += i)
				Eratos[j] = false;
	}

	int T=0;
	cin >> T;
	
	for (int i = 0; i < T; ++i)
	{
		int start=0, next=0;
		cin >> start>> next;
		
		memset(check, false, sizeof(check));
		memset(d, 0, sizeof(d));
		queue<int> q;
		q.push(start);
		d[start] = 0;
		check[start] = true;
		while (!q.empty())
		{
			int pos = q.front();
			q.pop();

			//4자리
			for (int i = 0; i < 4; ++i)
			{// 0~9
				for (int j = 0; j <= 9; ++j)
				{
					int cnext = change(pos, i, j);
					if (cnext != -1)
					{
						if (Eratos[cnext] == true && check[cnext]!=true)
						{
							q.push(cnext);
							check[cnext] = true;
							d[cnext] = d[pos] + 1;
						}
					}
				}
			}

		}
		cout << d[next] << '\n';
	}
}
