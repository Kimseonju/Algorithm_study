
#include <iostream>
#include <string>
#include<vector>
using namespace std;
char word[6] = { 'A','E','I','O','U','0' };

int check(string strcheck)
{
    reverse(strcheck.begin(), strcheck.end());

    int count = 0;
    for (int i = 0; i < strcheck.size(); ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (word[j] == strcheck[i])
            {
                if (j == 0)
                {
                    count++;
                }
                else
                {
                    if (i == 0)
                    {
                        count +=j+1
                    }
                    else
                        count+=pow(6, i)*j;
                }
                break;
            }
        }
        
    }
    return count;
}
int main()
{   




    string str;

    cin >> str;

    if (str.size() < 5)
    {
        int sizes = str.size();
        for (int i = 0; i < 5 - sizes; ++i)
        {
            str.push_back('0');
        }
    }
    int a=check(str);
    cout << a << endl;
    
}