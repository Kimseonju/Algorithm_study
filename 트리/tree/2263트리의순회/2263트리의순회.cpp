
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
void oneoneoneone()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int Inorder[100001];
int Postorder[100001];
vector<int> ans;
void sol(int root, int start, int end)
{
	for (int i = start; i >= end; --i)
	{
		if (Postorder[root] == Inorder[i])
		{
			cout << Postorder[root] << ' ';
			sol(root + i-1-start, i - 1, end);
			sol(root - 1, start, i);
		}
	}
}
int main()
{
	oneoneoneone();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> Inorder[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> Postorder[i];
	}
	int rootnumber = n - 1;

	sol(rootnumber, rootnumber, 0);



}
