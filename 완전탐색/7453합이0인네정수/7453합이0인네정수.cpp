#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


int N;
int main()
{
	cin >> N;

	vector<long long> A(N);
	vector<long long> B(N);
	vector<long long> C(N);
	vector<long long> D(N);

	vector<long long> Arr1;
	vector<long long> Arr2;

	
	for (int i = 0; i < N; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		A[i] = a;
		B[i] = b;
		C[i] = c;
		D[i] = d;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Arr1.push_back(A[i] + B[j]);
			Arr2.push_back(C[i] + D[j]);
		}
	}
	long long answer = 0;
	sort(Arr1.begin(), Arr1.end());
	sort(Arr2.begin(), Arr2.end());
	int pre;
		int end;
	for (int i = 0; i < Arr1.size(); i++) {

		pre = lower_bound(Arr2.begin(), Arr2.end(), -Arr1[i]) - Arr2.begin();
		end = upper_bound(Arr2.begin(), Arr2.end(), -Arr1[i]) - Arr2.begin();

		answer += (end - pre);
	}

	cout << answer;

}
