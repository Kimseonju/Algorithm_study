// 1107리모컨.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
bool number[11];
int N;
int possible(int c)
{
	if (c == 0)
	{
		if (number[0])
			return 0;

		else
			return 1;
	}
	int len=0;
	while (c > 0)
	{
		if (number[c % 10])
			return 0;
		len++;
		c /= 10;
	}
	return len;
}

int main()
{
	int f;
	cin >> N;
	cin >> f;
	int num;
	for (int i = 0; i < f; ++i)
	{
		cin >> num;
		number[num] = true;
	}

	int ans = N - 100; 
	if (ans < 0) {
		ans = -ans;
	}
	for (int i = 0; i <= 1000000; i++) { 
		int c = i;
		int len = possible(c); 
		if (len > 0) {
			int press = c - N; 
			if (press < 0) {
				press = -press; 
			}
			if (ans > len + press) {
				ans = len + press;
			}
		}
	}
	cout << ans;

}
