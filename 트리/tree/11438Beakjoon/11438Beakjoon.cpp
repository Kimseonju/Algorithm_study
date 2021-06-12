#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>
using namespace std;
int N, M;
vector<int> node[100001];
bool visit[100001];
int parent[100001];
int depth[100001];
int p[100001][20];

int max_level;

void getTree(int here, int parent)
{
	int len = node[here].size();
	for (int i = 0; i < len; i++)
	{
		int c = node[here][i];
		//부모와 가져온c가같다면 같은것 
		if (parent == c)
			continue;

		depth[c] = depth[parent] + 1;

		int there = node[here][i];
		if (there != parent)
			getTree(there, here);


	}
	p[here][0] = parent;
	max_level = (int)floor(log2(100001));

	for (int i = 1; i <= max_level; i++)
	{	int tmp = p[here][i - 1];
		p[here][i] = p[tmp][i - 1];
	}

	


}

int findparent(int left, int right)
{
	//더깊은노드
	if (depth[left] > depth[right])
	{
		swap(left, right);
	}
	//
	for (int i = max_level; i >= 0; i--)
	{
		if (depth[left] <= depth[p[right][i]])
			right = p[right][i];
	}

	int ans = left;
	for (int i=max_level; i >= 0;--i)
	{
		if (left == right)
		{
			break;
		}
		if (p[left][i] != p[right][i])
		{
			left = p[left][i];
			right = p[right][i];
		}
		ans = p[left][i];
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
	depth[0] = -1;
	getTree(1, 0);

	

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int left, right;
		cin >> left >> right;
		int a = findparent(left, right);
		printf("%d\n", a);
	}
}
