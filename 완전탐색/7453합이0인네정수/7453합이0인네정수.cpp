#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
int main()
{


	cin >> N;
	vector<vector<long long>>v(N);

	
	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < 4; ++k)
		{
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}


	int m = N / 2;
	N = N - m;
	vector<long long>vN;
	
	int num = 0;
	for (int i = 0; i < (2 << 2 * N); ++i)
	{
		int sum = 0;
		for (int j = 0; j < N; ++j)
		{
			int checkabcd =10^j;
			checkabcd = num / checkabcd;
			sum += v[j][checkabcd];
		}
		++num;
		
		vN.push_back(sum);
	}


	int ans = 0;
	




}

