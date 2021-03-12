// 11047_baekjoon.cpp 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int func(int a, int b)
{
	return a > b;
}
int main()
{
	int a, b;

	scanf_s("%d %d", &a, &b);
	int input;
	vector<int> coin(11);
	for (int i = 0; i < a; ++i)
	{
		cin >> coin[i];
	}
	int sum = 0;
	int count = 0;
	sort(coin.begin(), coin.end(), func);
	for (int i = 0; i < a; i++)
	{

		while (b - coin[i] >= 0)
		{

			count++;
			b -= coin[i];
		}
	}
	cout << count;
}