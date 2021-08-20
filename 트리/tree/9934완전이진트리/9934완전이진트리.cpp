#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int cnt = 1;
int K;
int A[1023 + 1];
vector<int> L[10 + 1];

void sol(int idx, int depth)
{
	if (depth == K-1)                 
	{
		L[depth].push_back(A[cnt++]); 
	}
	else
	{                                  
		sol(idx * 2, depth + 1);       
		L[depth].push_back(A[cnt++]);  
		sol(idx * 2 + 1, depth + 1);   
	}
}

int main()
{

	cin >> K;
	int S=pow(2, K)-1;

	for (int i = 1; i <= S; ++i)
	{
		int num;
		cin >> A[i];

	}
	sol(1, 0);
	for (int i = 0; i < K; i++) {
		for (int n : L[i]) {
			cout << n << ' ';
		} cout << endl;
	}
}