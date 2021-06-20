#include <iostream>
#include <queue>
#include <memory.h>
#include <string>
#include <algorithm>
using namespace std;
bool Eratos[4000001];
int N;
int p[300000];
int main()
{

	cin >> N;
	int pn = 0;
	for (int i = 2; i <= N; i++) {
		if (Eratos[i] == false) {
			p[pn++] = i;
			for (int j = i * 2; j <= N; j += i) {
				Eratos[j] = true;
			}
		}
	}

	int left = 0, right = 0;
	int sum = p[0];
	int ans = 0;
	while (left <= right && right < pn)
	{

		if (sum < N)
		{
			right += 1;
			if (right < pn) {
				sum += p[right];
			}
		}
		else if (sum == N)
		{
			ans++;

			right += 1;
			if (right < pn) {
				sum += p[right];
			}
		}
		else
		{
			sum -= p[left];
			left++;
		}
	}

	cout << ans;
}
