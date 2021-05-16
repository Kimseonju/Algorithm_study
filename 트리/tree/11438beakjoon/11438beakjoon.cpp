#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
vector<int> node[100001];
bool visit[100001];
int parent[100001];
int depth[100001];
int p[100001][20];


void bfs(int start)
{
	visit[start] = true;
	parent[start] = start;
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int inode = q.front();
		q.pop();

		for (int i = 0; i < node[inode].size(); ++i)
		{
			int nextnode = node[inode][i];
			if (!visit[nextnode])
			{
				visit[nextnode] = true;
				parent[nextnode] = inode;
				depth[nextnode] = depth[inode]+1;
				q.push(nextnode);
			}
		}
	}

}

int findparent(int left, int right)
{
	if (depth[left] < depth[right])
	{
		swap(left, right);
	}
	int iidist = depth[left] - depth[right]; //두노드의 깊이차이
	for (;;)
	{
		if (depth[left] == depth[right])
			break;
		left = parent[left];
	}
	int idepth = 0;
	int ans = 0;
	for (;idepth>=0;)
	{
	   /
		/if (p[left][idepth] == p[right][idepth])
		/{
		/	if (ans < p[left][idepth])
		/		ans = p[left][idepth];
		/}
		/if (left == right)
		/{
	   /
		/	if (ans < left){
		/		ans = left;
		/		break;
		/	}
		//}
		//++idepth;
	}
	return ans;
}
int main()
{
	cin >> N;

	for (int i = 0; i < N - 1; ++i)
	{
		int left, right;
		cin >> left >> right;

		node[left].push_back(right);
		node[right].push_back(left);
	}
	bfs(1);
	for (int i = 1; i <= N; ++i)
	{
		p[i][0] = parent[i];
	}
	for (int j = 1; j < 20; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			if (p[i][j - 1] != 0)
			{
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int left, right;
		cin >> left >> right;
		int a = findparent(left, right);
		printf("%d",a);
	}
	int a = 0;
}

