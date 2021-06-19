// 완전탐색.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int E, S, M;
int main()
{
    cin >> E >> S >> M;

    int a=1, b=1, c = 1;
    int year = 1;
    for (;;)
    {
        if (a == E && b == S && M == c)
        {
            break;
        }

        else
        {
            ++a;
            ++b;
            ++c;
            year++;

            if (a == 16)
                a = 1;

            if (b == 29)
                b = 1;

            if (c == 20)
                c = 1;
        }

    }
    cout << year;

}


