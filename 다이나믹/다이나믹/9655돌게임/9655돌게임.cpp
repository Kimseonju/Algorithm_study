

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;

	if (n / 3 % 2 == 0)
	{
		if (n % 3 % 2 == 0)
		{
			cout << "CY";
		}
		else
		{
			cout << "SK";
		}
	}
	else
	{
		if (n % 3 % 2 == 0)
		{
			cout << "SK";
		}
		else
		{
			cout << "CY";
		}
	}
}