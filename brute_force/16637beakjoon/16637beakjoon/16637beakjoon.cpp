// 16637beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

int N, M;
string str;
int k = 0;
int cnt = 0;
#define MIN_INT -2147483647
int ans_max = MIN_INT;
int cal(int a, int b, char c)
{
	int result = 0;
	if (c == '+')
	{
		result = a + b;
	}
	if (c == '-')
	{
		result = a - b;
	}
	if (c == '*')
	{
		result = a * b;
	}
	return result;
}


void abc(int a, int b)
{
	if (N-1 < a+2)
	{
		if (ans_max < b)
			ans_max = b;
		return;
	}

	if (a + 4 < N)
	{
		int kk = cal(str[a + 2] - '0', str[a + 4] - '0', str[a+3]);
		abc(a + 4, cal(b , kk, str[a+1]) );
	}
	abc(a + 2, cal(b, str[a + 2] - '0', str[a + 1]));
}
int main()
{
	cin >> N;
	cin >> str;

	abc(0, str[0]-'0');
	cout << ans_max;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
