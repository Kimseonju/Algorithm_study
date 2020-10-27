// 2231_baekjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{

	int N, M;
	int answer = 0;

	cin >> N;

	int a=N;
	while (a)
	{
		a /= 10;
		answer++;
	}
	//
	M =N- answer * 9;
	string k;
	
	for (;;) {
		if (M == N)
			break;
		int num = M;
		k = to_string(M);
		for (int i = 0; i < k.length(); ++i) {
			num +=k[i]-'0';
		}
		if (num == N)
			break;
		else
			M++;
	}

	if(M==N)
		cout << 0;
	else
		cout << M;
}
