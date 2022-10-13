#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;


    if (abs(a - b) == 1)
    {
        int nexta = a / 2 + a % 2;
        int nextb = b / 2 + b % 2;
        if (abs(nexta - nextb) == 0)
            return 1;
    }

    for (int i = 2;; ++i)
    {
        int nexta = a / 2 + a % 2;
        int nextb = b / 2 + b % 2;
        if (abs(nexta - nextb) == 0)
            return i - 1;
        a = nexta;
        b = nextb;
    }
    return -1;
}