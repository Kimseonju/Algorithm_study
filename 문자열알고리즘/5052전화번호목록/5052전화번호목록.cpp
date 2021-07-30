#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
	bool valid;
	bool bchildren;
	Node* children[10];
	Node()
	{
		valid = false;
		bchildren = false;
		for (int i = 0; i < 10; i++) {
			children[i] = nullptr;
		}
	}
};
vector<Node*> trie;
int t, n;
Node* init()
{
	Node* node = new Node;
	trie.push_back(node);

	return node;
}

bool add(Node* node, string& str, int index)
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

	int c = str[index] - '0';
	if (node->children[c] == nullptr)
	{
		Node* next = init();
		node->children[c] = next;
		node->bchildren = true;
	}
	return add(node->children[c], str, index + 1);
}

int main()
{
	cin >> t;

	while (t!=0)
	{
		--t;
		cin >> n;
		vector<string> word;
		string str;
		Node* root = init();
		bool check = true;
		for (int i = 0; i < n; ++i)
		{
			cin >> str;
			bool addcheck =add(root, str, 0);
			if (!addcheck)
				check = false;
		}
		if (check)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		trie.clear();
	}
}
