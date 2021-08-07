#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
	bool valid;
	bool bchildren;
	int children[30];
	Node()
	{
		valid = false;
		bchildren = false;
		for (int i = 0; i < 30; i++) {
			children[i] = -1;
		}
	}
};
vector<Node> trie;
int Init()
{
	Node node;
	trie.push_back(node);
	return trie.size()-1;
}

bool Add(int node, string& str, int index)
{
	if (index == str.size())
	{
		if (trie[node].bchildren)
			return false;
		trie[node].valid = true;
		return true;
	}

	if (trie[node].valid)
		return false;

	int c = str[index] - 'a';
	if (trie[node].children[c] == -1)
	{
		int next= Init();
		trie[node].children[c] = next;
		trie[node].bchildren = true;
	}

	return Add(trie[node].children[c], str, index + 1);
}
bool Search(int node, string& str, int index)
{
	if (index == str.size())
	{
		return true;
	}
	if (trie[node].valid)
	{
		return true;
	}
	int c = str[index] - 'a';
	if (trie[node].children[c] == -1)
	{
		return false;
	}
	else
	{
		return Search(trie[node].children[c], str, index + 1);
	}
}

int N, Q;
int main()
{
	cin >> N;
	int root = Init();
	string str;
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		Add(root, str, 0);
	}


	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		cin >> str;

		reverse(str.begin(), str.end());

		string checkstr;
		bool bcheckstr = false;
		for (int i = 0; i < str.size(); ++i)
		{
			checkstr = str[i] + checkstr;
			bool check = Search(root, checkstr, 0);
			if (check)
				bcheckstr = true;
		}

		if (bcheckstr)
			cout << "YES" << '\n';

		else
			cout << "NO" << '\n';
	}

}
