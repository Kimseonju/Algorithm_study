
#include <iostream>
using namespace std;
long long int N, M, K;
long long int fpowa(long long C, long long int n)
{
	if (n == 0)
		return 1;

	long long int ans = fpowa(C,n / 2);

	ans = (ans * ans) % K;
	if (n % 2)
		ans = ans * C % K;

	return ans;
}
int main()
{
	cin >> N;


	K = 1000000007;

	for (int i = 0; i < N; ++i)
	{
		cin >> M;
		//2의 곱으로 늘어남 1은 0 2는 1 3는 2  4는 4
		//2^0 =1 
		long long int c = fpowa(2, M-2);

		cout << c << '\n';
	}



}
