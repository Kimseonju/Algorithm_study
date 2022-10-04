// 차량번호판1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <string>

int main()
{
	string str;
	//c는 26
	//d는 10
	cin >> str;
	//1이면 문자 2면 숫자
	int check = 0;
	int ans = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'c')
		{
			if (ans == 0)
			{
				ans = 26;
				
			}
			else
			{
				if (check == 1)
				{
					int temp = ans;
					ans *= 26;
					ans -= temp;
				}
				else
				{

					ans *= 26;
				}
			}
			check = 1;
		}
		else if (str[i] == 'd')
		{
			if (ans == 0)
			{
				ans = 10;
				
			}
			else
			{
				if (check == 2)
				{
					int temp=ans;
					ans *= 10;
					ans -= temp;
				}
				else
				{
					ans *= 10;
				}
			}
			check = 2;
		}
	}
	cout << ans;
}