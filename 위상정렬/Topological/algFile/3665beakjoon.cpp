// 3665beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <cstring>
using namespace std;

int num;
int n;
int t[500];
int m;
int mat[501][501];
int in[501];
int main()
{

	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		memset(mat, 0, sizeof(mat));
		memset(in, 0, sizeof(in));
		memset(t, 0, sizeof(t));
		
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> t[i];
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				mat[t[i]][t[j]] = 1;
				in[t[j]]++;
			}
		}

		cin >> m;
		int a, b;
		for (int i = 0; i < m; ++i)
		{
			cin >>a >> b;
			if (mat[a][b]) {
				mat[a][b] = 0;
				mat[b][a] = 1;
				in[b]--, in[a]++;
			}
			else {
				mat[b][a] = 0;
				mat[a][b] = 1;
				in[a]--, in[b]++;
			}
		}
		queue<int> q;
		vector<int> ans;
		for (int i = 1; i <= n; ++i)
		{
			if (in[i] == 0)
				q.push(i);
		}
		bool check=false;
		while (!q.empty())
		{
			if (q.size() >= 2)
			{
				check = true;
				break;
			}
			int z = q.front();
			q.pop();
			ans.push_back(z);
			for (int i = 1; i <= n; ++i)
			{
				if (mat[z][i])
				{
					in[i]--;
					if (in[i] == 0)
					{
						q.push(i);
					}
				}
			}
		}
		if (ans.size() == n)
		{
			for (int i = 0; i < n; ++i)
			{
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
		else if(check)
		{
			cout << "?" << endl;
		}
		else
			cout << "IMPOSSIBLE" << endl;


	}
	

}
