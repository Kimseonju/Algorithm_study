#include <iostream>


using namespace std;
int com[105];
int Find(int x)
{
	if (x == com[x] || -1 == com[x])
		return x;
	else
		return com[x] = Find(com[x]);
}

void group(int one, int two)
{
	one = Find(one);
	two = Find(two);
	if(one!=two)
		com[two] = one;
}


int N, M;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	ios_base::sync_with_stdio(false);

	cin >> N;
	cin >> M;
	com[0] = -1;
	for (int i = 1; i <= N; ++i)
	{
		com[i] = i;
	}
	int one, two;
	for (int i = 0; i < M; ++i)
	{
		cin >> one >> two;
		group(one, two);
	}
	int ans = 0;
	for (int i = 2; i <= N; ++i)
	{
		if (Find(1) == Find(i))
			ans++;

	}
	cout << ans;

}
