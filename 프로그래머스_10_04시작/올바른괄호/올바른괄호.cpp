#include<string>
#include <iostream>
#include <deque>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    deque<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ')')
        {
            if (st.size() == 0)
                return false;
            if (st[0] != '(')
                return false;
            st.pop_front();
            continue;
        }
        st.push_back(s[i]);
    }
    if (st.size() != 0)
        return false;
    return true;
}