// 2798_baekjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int N;
int M;
int answer;
int pluss;
int base[100];
bool check[100];
void func(int x) {
	if (x == 3) {
		if(M>=pluss){
			if (answer < pluss)
				answer = pluss;
		}
		return;
	}
	for (int i = 0; i < N; ++i) {
		if(!check[i]){
			pluss += base[i];
			check[i] = true;
			func(x + 1);
			pluss -= base[i];
			check[i] = false;
		}
	}

}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> base[i];
	}
	func(0);

	cout << answer;
}

