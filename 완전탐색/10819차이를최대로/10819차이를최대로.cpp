// 10819차이를최대로.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int N;

int calculate(vector<int>& a)
{
    int sum=0;
    for (int i = 1; i < arr.size(); ++i)
    {
        sum +=abs(a[i - 1] - a[i]);
    }
    return sum;
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    do
    {
        int temp = calculate(arr);
        ans = max(ans, temp);
        
    } while (next_permutation(arr.begin(), arr.end()));
    cout << ans;
}
