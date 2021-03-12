
#include <iostream>
using namespace std;

int a, b;
bool check[10];
int num[10];
void func(int m)
{
	if (b == m-1) {
		for (int i = 1; i < m; ++i) {
			cout << num[i] << " ";
		}
		cout << "\n"; //endl 호출 시 출력버퍼를 비워주는 과정(flush)생김
		return;
	}
	for (int i = num[m-1]; i <= a; ++i) {
		if (!check[i])
		{
			num[m] = i;
			check[i] = true;
			func(m + 1);
			check[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	num[0]=1;
	func(1);
	int c = 0;

}
