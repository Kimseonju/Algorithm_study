// 1339beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
int num[10];

int N;
using namespace std;

string strCheck;
int temp;

vector<int> an;
bool desc(int a, int b) { return a > b; }
int answer;
int main()
{
	cin >> N;
	for (int i = 0; i < 10; ++i)
	{
		an.push_back(0);
	}
	string str;
	for (int i = 0; i < N;  ++i)
	{
		cin >> str;
		for (int j = 0; j < str.size(); ++j)
		{
			temp = -1;
			for (int k = 0; k < strCheck.size(); ++k)
			{
				if (str[j] == strCheck[k]){ 
					temp = k;//만약 알파벳이 한번이상 사용되었다면
					break;
				}
			}
			if (temp == -1)
			{
				strCheck += str[j];
				temp = strCheck.size() - 1;
			}
			//알파벳번호 부여완료

			an[temp] += pow(10, str.size() - j - 1);
		}
	}
	sort(an.begin(), an.end(), desc);
	int b = 9;
	for (int i = 0; i < an.size(); ++i)
	{
		answer += an[i] * b;
		--b;
	}

	cout << answer;
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
