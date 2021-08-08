
#include <iostream>
using namespace std;
long long int N, M, K;
long long int fpowa(long long int C, long long int n)
{
	if (n == 1) 
		return C % K;

	long long int ans = fpowa(C, n / 2);

	ans = (ans * ans) % K;
	if (n % 2)
		ans = ans * C % K;

	return ans;

}
int main()
{
	cin >> N >> M >> K;


	long long int c = fpowa(N, M);

	cout << c;
}
