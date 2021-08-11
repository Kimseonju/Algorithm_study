#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class ListNode
{
public:
	ListNode* Prev;
	ListNode* Next;
	int data;
	ListNode() : Prev(nullptr), Next(nullptr), data(-1)
	{}
	~ListNode()
	{}
};


class CNode
{
public:
	ListNode* StartNode;
	ListNode* EndNode;
	int m_size;
public:
	int size()
	{
		return m_size;
	}
		

	CNode() : StartNode(new ListNode()),
		EndNode(new ListNode()),
		m_size(0)
	{
		StartNode->Next = EndNode;
		EndNode->Prev = StartNode;
	}
	~CNode()
	{
		for (int i = 0; i < m_size; ++i)
		{
			ListNode* node = StartNode->Next;
			StartNode->Next = StartNode->Next->Next;
			delete node;
		}
		delete StartNode;
		delete EndNode;
	}

	void push(int i)
	{
		ListNode* node = new ListNode();
		node->data = i;

		ListNode* tempnode=StartNode->Next;
		StartNode->Next = node;
		node->Prev = StartNode;
		node->Next = tempnode;
		m_size++;
	}

	int pop()
	{
		ListNode* node = StartNode->Next;
		ListNode* tempnode=node->Next;
		StartNode->Next = tempnode;
		tempnode->Prev = StartNode;
		int a = node->data;
		delete node;
		m_size--;
		return a;
	}

	int top()
	{
		return StartNode->Next->data;
	}

};

CNode st;
vector<int> vcheck;
vector<int> play;
int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> m;
		vcheck.push_back(m);
	}
	int checknum = 0;
	for (int i = 1; i <= n; ++i)
	{
		st.push(i);
		play.push_back(1);
		int size = st.size();
		for(; size !=0;)
		{
			if (vcheck[checknum] == st.top())
			{
				st.pop();
				play.push_back(0);
				checknum++;
				size = st.size();
			}
			else
			{
				break;
			}
		}
	}

	if (st.size() == 0)
	{
		for (int i = 0; i < play.size(); ++i)
		{
			if (play[i] == 1)
			{
				cout << '+' << '\n';
			}
			else
			{
				cout << '-' << '\n';
			}
		}
	}
	else
	{
		cout << "NO";
	}
}
