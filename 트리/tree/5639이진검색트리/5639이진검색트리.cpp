#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild = 0, rightChild = 0;

}node;

int cnt = 0;
node nodee[10001];

void sol(int start, int end)
{
	if (end == start)
	{
		return;
	}
		
	int idx = start + 1;
	while (idx < cnt && nodee[start].data >= nodee[idx].data)
		idx++;
	sol(start + 1, idx);
	sol(idx, end);
	cout << nodee[start].data << '\n';
	
	
}
int main()
{
	string str;
	while (getline(cin, str)) {
		
		int num=atoi(str.c_str());
		nodee[cnt].data = num;
		cnt++;
	}
	sol(0, cnt);

}