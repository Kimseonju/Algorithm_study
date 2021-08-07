#include <iostream>

using namespace std;

int a[100001];
int S[300001];


int N, M;

int main()
{
	cin >> N >> M;
	int sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &a[i]);
		S[i] = S[i - 1] + a[i];

	}
	int start=0, end=0;
	
	for (int i = 0; i < M; ++i)
	{
		int ans = 0;

		scanf("%d %d", &start, &end);

		ans = S[end]- S[start-1];
		
		printf("%d\n", ans);


	}
}
