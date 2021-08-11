
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

int parent[1000000];

int getparent(int num)
{
	if (parent[num] == num)
		return num;
	else
		return parent[num] = getparent(parent[num]);
}

void unionparent(int a, int b)
{
	a = getparent(a);
	b = getparent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
int findparent(int a, int b)
{
	int pa = getparent(a);
	int pb = getparent(b);
	if (pa == pb)
		return 1;
	else
		return 0;
}

struct node
{
	int m_start;
	int m_end;
	int m_direction;

	node(int start, int end, int direction)
	{
		m_start = start;
		m_end = end;
		m_direction = direction;
	}

	bool operator<(node& nnode)
	{
		return m_direction < nnode.m_direction;
	}
};

vector<node>vnode;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vnode.push_back(node(a, b, c));
	}
	int MaxNode = n - 1;
	int cntNode = 0;
	int sum = 0;
	//최소값으로 정렬
	sort(vnode.begin(), vnode.end());

	for (int i = 0; i <= n; ++i)
	{
		parent[i] = i;
	}
	for (int i = 0; i < vnode.size(); ++i)
	{
		if (!findparent(vnode[i].m_start, vnode[i].m_end))
		{
			cntNode++;
			unionparent(vnode[i].m_start, vnode[i].m_end);

			if (cntNode == MaxNode)
				break;
			sum += vnode[i].m_direction;
		}
	}
	cout << sum;
}
