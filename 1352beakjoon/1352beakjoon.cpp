// 1352beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

int N;
int temp;
bool check = false;
int cnt = 0;
string str;
void func(int n)
{
	cnt++;
	temp += n;
	if (temp > N)
		check = true;
	else if (temp == N)
		return;
	func(n + 1);

}
int main()
{
	cin >> N;
	func(1);
	int c = 97;
	for (int i = 0; i < cnt; ++i)
	{
		char a = c;
		str += ""+a;
		c++;

	}



}

