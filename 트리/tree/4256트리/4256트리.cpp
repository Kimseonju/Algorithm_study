
#include <iostream>
#include <vector>
using namespace std;

int preorder[1001];
int inorder[1001];

void sol(int root, int s, int e) {
	for (int i = s; i < e; i++) {
		if (inorder[i] == preorder[root]) {


			sol(root + 1, s, i);
			sol(root + i + 1 - s, i + 1, e);
			cout << preorder[root] << " ";
		}
	}
}

int main(void) {

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{

		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> preorder[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> inorder[i];
		}
		sol(0, 0, n);
		cout << '\n';
	}
	return 0;
}
