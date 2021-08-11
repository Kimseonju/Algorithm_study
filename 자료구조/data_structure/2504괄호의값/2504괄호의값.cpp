#include <iostream>

#include <stack>
#include <string>
using namespace std;
int main()
{
    int temp = 1, result = 0;
    string str;
    cin >> str;
    stack<char> st;

    for (int i = 0; i != str.length(); i++)
    {
        if (str[i] == '(')
        {
            temp *= 2;
            st.push('(');
        }
        else if (str[i] == '[')
        {
            temp *= 3;
            st.push('[');
        }
        else if (str[i] == ')')
        {
            if (st.empty()) {
                std::cout << "0";
                return 0;
            }
            else if (str[i - 1] == '(')
            {
                result += temp;
                temp = temp / 2;
                st.pop();
            }
            else if (st.top() == '(')
            {
                st.pop();
                temp = temp / 2;
            }
            else
            {
                std::cout << "0";
                return 0;
            }
        }
        else if (str[i] == ']')
        {
            if (st.empty()) {
                cout << "0";
                return 0;
            }
            else if (str[i - 1] == '[')
            {
                result += temp;
                temp = temp / 3;
                st.pop();
            }
            else if (st.top() == '[')
            {
                st.pop();
                temp = temp / 3;
            }
            else
            {
                std::cout << "0";
                return 0;
            }
        }
    }
    if (st.empty())
        cout << result;
    else
        cout << "0";

    return 0;
}