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
	Node* children[30];
	Node()
	{
		valid = false;
		bchildren = false;
		for (int i = 0; i < 30; i++) {
			children[i] = nullptr;
		}
	}

	~Node()
	{
		for (int i = 0; i < 30; i++) {

			if (children[i] != nullptr)
			{
				delete children[i];
				children[i] = nullptr;
			}
		}
	}
};
vector<Node*> trie;
Node* Init()
{
	Node* node = new Node;
	trie.push_back(node);
	return node;
}

bool Add(Node* node, string& str, int index)
{
	if (index == str.size())
	{
		if (node->bchildren)
			return false;
		node->valid = true;
		return true;
	}

	if (node->valid)
		return false;

	int c = str[index] - 'a';
	if (node->children[c] == nullptr)
	{
		Node* next = Init();
		node->children[c] = next;
		node->bchildren = true;
	}

	return Add(node->children[c], str, index + 1);
}
bool Search(Node* node, string& str, int index)
{
	if (index == str.size())
	{
		return true;
	}
	int c = str[index] - 'a';
	if (node->children[c] == nullptr)
	{
		return false;
	}
	else
	{
		return Search(node->children[c], str, index + 1);
	}
}

int N, Q;
int main()
{
	cin >> N;
	Node* root = new Node;
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
