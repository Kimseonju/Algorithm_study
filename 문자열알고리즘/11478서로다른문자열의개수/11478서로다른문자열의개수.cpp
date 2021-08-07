// 11478서로다른문자열의개수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string inputstr;

    cin >> inputstr;

    vector<string> vstr;

    for (int i = 0; i < inputstr.size(); ++i)
    {
        const char* pchar = &inputstr[i];

        string str(pchar);
        vstr.push_back(str);


    }
    int size = inputstr.size();
    vector<vector<int>> group(30,  vector<int>(size+ 1));


    vector<string> Allstr;
    for (int i = 0; i < vstr.size(); ++i)
    {
        int size = vstr[i].size();
        string str = vstr[i];
        for (int j = 0; j < vstr[i].size(); ++j)
        {
            for (int k = 0; k < str.size(); ++k)
            {
                group[str[k] - 'a'][str.size()]= 1;
            }
            str.pop_back();


        }
    }
    int b = 0;
}
