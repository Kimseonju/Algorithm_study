#include <iostream>
#include <queue>
#include <memory.h>
#include <string>
#include <algorithm>
using namespace std;

int T;


bool check[10002];
int dist[10001];
int from[10002];
int cnext[10002];
char how[10002];
int main()
{
	cin >> T;
	int start = 0, end = 0;
	for (int i = 0; i < T; ++i)
	{
		cin >> start >> end;

		queue<int> q;
		
		q.push(start);

		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));

		check[start] = true;
		dist[start] = 0;
		from[start] = -1;

		while (!q.empty())
		{
			int pos=q.front();
			q.pop();

			//D작업
			int Dpos = pos * 2;
			if (Dpos >= 10000)
				Dpos = Dpos % 10000;
			if (!check[Dpos])
			{
				q.push(Dpos);
				check[Dpos] = true;
				from[Dpos] = pos;
				how[Dpos] = 'D';
			}
			

			//S
			int Spos = pos-1;
			if (Spos <= -1)
			{
				Spos = 9999;
			}
			if (!check[Spos])
			{
				q.push(Spos);
				check[Spos] = true;
				from[Spos] = pos;
				how[Spos] = 'S';
			}

			//L
			int Lpos = (pos % 1000) * 10 + pos / 1000;
			if (!check[Lpos])
			{
				q.push(Lpos);
				check[Lpos] = true;
				from[Lpos] = pos;
				how[Lpos] = 'L';
			}

			//R
			int Rpos = (pos / 10) + (pos % 10) * 1000;
			if (!check[Rpos])
			{
				q.push(Rpos);
				check[Rpos] = true;
				from[Rpos] = pos;
				how[Rpos] = 'R';
			}


		}
		string ans = "";
		while (start != end) {
			ans += how[end];
			end = from[end];
		}
		reverse(ans.begin(), ans.end());
		cout << ans<<'\n';


	}


}
