#include <iostream>
using namespace std;


int main()
{
	int N;

	cin >> N;

	int fivecoin = N / 5;
	int re = N % 5;

	if (re % 2 != 0 && fivecoin>0)
	{
		fivecoin--;
		re += 5;
	}

	int twocoin = re / 2;

	if (re % 2 != 0)
	{
		cout << "-1";
	}
	else
		cout << fivecoin + twocoin;

}

