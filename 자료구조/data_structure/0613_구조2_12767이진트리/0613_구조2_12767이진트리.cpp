#include <iostream>
#include <vector>
using namespace std;
class Map {
	

	class Node
	{
	private:
		int Data;
		Node* m_Parent;
		Node* m_Left;
		Node* m_Right;

	public:
		Node(int data)
			:Data(data), m_Parent(nullptr), m_Left(nullptr), m_Right(nullptr)

		
		{}
		~Node() {}
		bool insert(Node* _Node)
		{
			//작다면
			if (Data > _Node->Data)
			{
				//빈공간
				if (nullptr == m_Left)
				{
					m_Left = _Node;
					_Node->m_Parent = this;
					return true;
				}
				//아니라면
				m_Left->insert(_Node);
				return true;
			}
			//크다면
			else if (Data < _Node->Data)
			{
				//빈공간
				if (nullptr == m_Right)
				{
					m_Right = _Node;
					_Node->m_Parent = this;
					return true;
				}
				//아니라면
				m_Right->insert(_Node);
				return true;
			}
			//같다면
			else
			{
				return false;
				//오류인뎁..
			}
		}
	};

private:
	Node* m_Root;
	size_t m_Size;

	void insert(int _Value)
	{
		if (nullptr == m_Root)
		{
			m_Root = new Node(_Value);
			return;
		}

		Node* NewNode = new Node(_Value);

		m_Root->insert(NewNode);
		++m_Size;
	}

public:

	Map():m_Root(nullptr), m_Size(0)
	{}

	~Map()
	{}
};



vector<Map*> a;
int N, K;
int _data;
int main()
{
	a.push_back(new Map());
	cin >> N;
	bool check = false;
	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < K; ++k)
		{
			cin >> _data;
			for (int l = 0; l < a.size(); ++l)
			{
				
				
			}

		}
	}

}
