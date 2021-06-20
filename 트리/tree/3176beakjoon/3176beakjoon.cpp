
#include <iostream>
#include <vector>
using namespace std;
int N, K;
vector<pair<int, int>> node[100001];
bool check[100001];
int main()
{
	cin >> N;
	int A, B, C;
	for (int i = 0; i < N; ++i)
	{
		cin >> A >> B >> C;
		node[A].push_back(make_pair(B, C));
		node[B].push_back(make_pair(A, C));
	}




	cin >> K;
	int D, E;
	int MIN = 0;
	int MAX = 10000000;
	for (int i = 0; i < K; ++i)
	{
		cin >> D >> E;
	}
}
