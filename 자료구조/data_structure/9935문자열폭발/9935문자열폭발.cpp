#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string str;
    string Checkstr;
    cin >> str >> Checkstr;

    string ans = str;
    stack<int> stint;
    stack<char> stchar;
    int count = 0;
    bool bBombFind = false;
    for (int i = 0; i < str.size(); ++i)
    {
        for (int j = 0; j < Checkstr.size(); ++j)
        {
            if (str[i] == Checkstr[j])
            {
                if (0 <count)
                {
                    if (Checkstr[count] == str[i])
                    {
                        count++;
                        stint.push(i);
                        stchar.push(str[i]);
                    }
                    else
                        count = 0;
                }
                if (0 == j)
                {
                    count=1;
                    stint.push(i);
                    stchar.push(str[i]);
                }
            }
            if (count == Checkstr.size())
            {
                bBombFind = true;
                count = 99;
            }
        }
        if (bBombFind)
        {
            bBombFind = false;
            for (int k = 0; k < Checkstr.size(); ++k)
            {
                ans[stint.top()] = '^';
                stint.pop();
                stchar.pop();
            }
            if (stchar.empty())
            {
                count = 0;
                continue;
            }
                


            char c=stchar.top();
            for (int k = Checkstr.size()-1; k >=0 ; --k)
            {
                if (Checkstr[k] == c)
                {
                    count = k + 1;
                    break;
                }
            }
            if (count == 99)
                count = 0;
        }
    }
    int countc = 0;
    for (int i = 0; i < ans.size(); ++i)
    {
        if (ans[i] == '^')
            continue;
        ++countc;
    }
    
    if (countc > 0)
    {
        for (int i = 0; i < ans.size(); ++i)
        {
            if (ans[i] == '^')
                continue;
            cout << ans[i];
        }
    }
    else
    {
        cout << "FRULA";
    }

}