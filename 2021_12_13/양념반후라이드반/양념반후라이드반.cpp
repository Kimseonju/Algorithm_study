// 양념반후라이드반.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <string>

int main()
{   
    int A, B, C, X, Y;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;
    cin >> Y;

    C *= 2;
    int C_Count = 0;
    if (X < Y)
    {
        C_Count = X;
        X = 0;
        Y -= C_Count;
    }
    else
    {
        C_Count = Y;
        Y = 0;
        X -= C_Count;
    }
    int ans = 0;
    if (A + B < C)
    {
        ans=C_Count* (A + B);
        if (A > C)
        {
            ans += X * C;
        }
        else
        {
            ans += X * A;
        }
        if (B > C)
        {
            ans += Y * C;
        }
        else
        {
            ans += Y * B;
        }
    }
    else
    {

        ans = C_Count * (C);
        if (A > C)
        {
            ans += X * C;
        }
        else
        {
            ans += X * A;
        }
        if (B > C)
        {
            ans += Y * C;
        }
        else
        {
            ans += Y * B;
        }
    }
    cout << ans;
}

