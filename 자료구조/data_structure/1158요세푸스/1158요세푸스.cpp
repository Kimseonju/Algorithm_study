#include <iostream>
int N, K;
using namespace std;
#include <queue>

class ListNode
{
public:
	ListNode* Prev;
	ListNode* Next;
	int data;
	ListNode(): Prev(nullptr), Next(nullptr), data(-1)
	{}
	~ListNode()
	{}
};

class CNode
{
	ListNode* m_StartNode;
	ListNode* m_EndNode;
	int m_size;
public:

	int size()
	{
		return m_size;
	}

	CNode() : m_StartNode(new ListNode()), 
		m_EndNode(new ListNode()),
		m_size(0)
	{
		m_StartNode->Next = m_EndNode;
		m_EndNode->Prev = m_StartNode;
	}
	~CNode()
	{
		for (int i = 0; i < m_size; ++i)
		{
			ListNode* node = m_StartNode->Next;
			m_StartNode->Next = m_StartNode->Next->Next;
			delete node;
		}
		delete m_StartNode;
		delete m_EndNode;
	}
	void push(int num)
	{
		ListNode* Node = new ListNode();
		Node->data = num;

		m_EndNode->Prev->Next = Node;
		Node->Prev = m_EndNode->Prev;

		m_EndNode->Prev = Node;
		Node->Next = m_EndNode;


		m_size++;
	}

	int pop()
	{
		int data=m_StartNode->Next->data;
		ListNode* node= m_StartNode->Next;

		m_StartNode->Next->Next->Prev = m_StartNode;
		m_StartNode->Next = m_StartNode->Next->Next;

		m_size--;
		delete node;
		return data;
	}
};
int main()
{
	cin >> N >> K;
	CNode node;
	CNode rqnode;

	for (int i = 1; i <= N; ++i)
	{
		node.push(i);
	}
	int a = 0;

	while (node.size() != 0)
	{
		int check = node.pop();
		a++;

		if (a % K==0)
		{
			rqnode.push(check);
		}
		else
		{
			node.push(check);
		}

	}
	cout << "<";
	while (true)
	{

		cout << rqnode.pop();
		if (rqnode.size() == 0)
			break;
		cout << ", ";
	}
	cout << ">";
}
