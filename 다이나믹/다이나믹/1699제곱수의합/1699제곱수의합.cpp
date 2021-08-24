﻿

#include <iostream>
using namespace std;

int d[100002];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i)
	{
		d[i] = 47483647;
	}

	for (int i = 1; i*i <= n; ++i)
	{
		d[i * i] = 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j * j <= i; ++j)
		{
			d[i] = min(d[i],d[j * j] + d[i - j * j]);
		}
	}
	cout << d[n];

}