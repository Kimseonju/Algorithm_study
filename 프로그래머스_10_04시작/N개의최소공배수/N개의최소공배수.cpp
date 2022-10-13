#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int num1, int num2)
{
    if (num2 == 0) return num1;
    else return gcd(num2, num1 % num2);
}
int solution(vector<int> arr)
{
    int answer = 0;
    sort(arr.begin(), arr.end());
    if (arr.size() == 1)
        return arr[0];
    for (int i = 0; i < arr.size(); ++i)
    {
        arr[i + 1] = (arr[i] * arr[i + 1]) / gcd(arr[i + 1], arr[i]);
    }



    return arr[arr.size() - 1];
}