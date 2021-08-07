#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
int T;

int n;
int m;

int main()
{
	cin >> T;
	cin >> n;

	vector<int>vn(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vn[i];
	}

	cin >> m;
	vector<int>vm(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> vm[i];
	}

	sort(vn.begin(), vn.end());
	sort(vm.begin(), vm.end());


	int nleft=0;
	int nright=vn.size()-1;

	int mleft=0;
	int mright=vm.size()-1;
	
	int check = 0;
	while (nleft == nright)
	{
		check += nleft;




	}

}
