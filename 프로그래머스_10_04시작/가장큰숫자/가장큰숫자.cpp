#include <string>
#include <vector>

using namespace std;

string GetBinaryNumber(int n)
{
    string ret = "";
    while (n > 0)
    {
        int remain = n % 2;
        n /= 2;
        ret = to_string(remain) + ret;
    }
    return ret;
}
int GetBinaryCount(string Binarystr)
{
    int ret = 0;
    for (int i = 0; i < Binarystr.size(); ++i)
    {
        if (Binarystr[i] == '1')
            ret++;
    }
    return ret;
}
int solution(int n)
{
    int answer = 0;
    string binarystr_n = GetBinaryNumber(n);
    int binaryCount = GetBinaryCount(binarystr_n);
    for (int i = n + 1;; i++)
    {
        string binarystr_i = GetBinaryNumber(i);
        int binaryCount_i = GetBinaryCount(binarystr_i);
        if (binaryCount == binaryCount_i)
            return i;
    }
}