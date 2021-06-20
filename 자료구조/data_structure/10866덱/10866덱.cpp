
#include <iostream>
#include <string>
using namespace std;
int N;
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
	void push_front(int num)
	{
		ListNode* Node = new ListNode();
		Node->data = num;

		m_StartNode->Next->Prev = Node;
		Node->Next = m_StartNode->Next;

		m_StartNode->Next = Node;
		Node->Prev = m_StartNode;

		m_size++;
	}

	void push_back(int num)
	{
		ListNode* Node = new ListNode();
		Node->data = num;

		m_EndNode->Prev->Next = Node;
		Node->Prev = m_EndNode->Prev;

		m_EndNode->Prev = Node;
		Node->Next = m_EndNode;


		m_size++;
	}

	int pop_front()
	{
		if (m_size == 0)
			return -1;
		int data = m_StartNode->Next->data;
		ListNode* node = m_StartNode->Next;

		m_StartNode->Next->Next->Prev = m_StartNode;
		m_StartNode->Next = m_StartNode->Next->Next;

		m_size--;
		delete node;
		return data;
	}

	int pop_back()
	{
		if (m_size == 0)
			return -1;

		int data = m_EndNode->Prev->data;
		ListNode* node = m_EndNode->Prev;

		m_EndNode->Prev->Prev->Next = m_EndNode;
		m_EndNode->Prev = m_EndNode->Prev->Prev;

		m_size--;
		delete node;
		return data;
	}

	int front()
	{
		if (m_size == 0)
			return -1;

		return m_StartNode->Next->data;
	}

	int back()
	{
		if (m_size == 0)
			return -1;

		return m_EndNode->Prev->data;	
	}

	bool empty()
	{
		if (m_size == 0)
			return 1;
		return 0;
	}
};


int main()
{
	CNode deq;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		if ("push_back" == str)
		{
			int a;
			cin >> a;
			deq.push_back(a);
		}
		if ("push_front" == str)
		{

			int a;
			cin >> a;
			deq.push_front(a);
		}
		if ("pop_front" == str)
		{
			cout << deq.pop_front() << endl;
		}
		if ("pop_back" == str)
		{
			cout << deq.pop_back() << endl;
		}
		if ("size" == str)
		{
			cout << deq.size() << endl;
		}
		if ("empty" == str)
		{
			cout << deq.empty() << endl;
		}
		if ("front" == str)
		{
			cout << deq.front() << endl;
		}
		if ("back" == str)
		{
			cout << deq.back() << endl;
		}
	}
}
