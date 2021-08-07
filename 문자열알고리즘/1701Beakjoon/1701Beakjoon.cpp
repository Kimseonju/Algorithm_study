#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> preprocessing(string p) {
    int Size = p.size();
    vector<int> pi(Size, 0);
    int j = 0;
    for (int i = 1; i < Size; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
        {
            pi[i] = j + 1;
            j++;
        }
    }
    return pi;
}
//뒤에서부터 중복된것이 있는지 체크
//reverse를 안하면 앞에서부터만 계속 체크해대서 뒤에서부터 넣어줌
int main()
{

    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    int ans = 0;
    string checkstr = "";
    for (char c : str)
    {
        checkstr = c + checkstr;
        vector<int> next = preprocessing(checkstr);
        int Size = next.size();
        for (int i = 0; i < Size; i++)
        {
            if (ans < next[i])
            {
                ans = next[i];
            }
        }
    }
    cout << ans;
}