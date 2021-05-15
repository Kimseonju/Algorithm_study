#include <iostream>
#include <vector>
using namespace std;
int N;
typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild=0, rightChild=0;

}node;

//전위
void preorder(treePointer ptr)
{
	if (ptr)
	{
		if (ptr->data != '.')
			cout << ptr->data;
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

//중위
void inorder(treePointer ptr)
{
	if (ptr)
	{
		inorder(ptr->leftChild);
		if(ptr->data!='.')
			cout << ptr->data;
		inorder(ptr->rightChild);
	}
}
//후위
void postorder(treePointer ptr)
{
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		if (ptr->data != '.')
			cout << ptr->data;
	}
}
int main()
{
	cin >> N;
	vector<char> v[27];
	node node[27];

	for (int i = 0; i < N; ++i)
	{
		v[i].push_back('A'+i);
	}
	for (int i = 0; i < N; ++i)
	{
		char a;
		cin >> a;
		for (int j = 0; j < 2; ++j)
		{
			char b;
			cin >> b;
			v[a-'A'].push_back(b);
		}
	}
	for (int i = 0; i < N; ++i)
	{
		node[i].data = v[i][0];
		int a = v[i][1] - 'A';
		if(v[i][1]!='.')
			node[i].leftChild = &node[v[i][1]-'A'];
		if (v[i][2] != '.')
			node[i].rightChild = &node[v[i][2] - 'A'];
	}
	
	preorder(node);
	cout << "\n";
	inorder(node);
	cout << "\n";
	postorder(node);

}
