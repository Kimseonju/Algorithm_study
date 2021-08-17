
#include <iostream>
#include <vector>
using namespace std;

int S, K;
int main()
{
    cin >> S >> K;

    vector<int> a;

    int t1 = S / K;
    int t2 = S % K;
    for (int i = 0; i < K; ++i)
    {
        a.push_back(t1);
    }
    int cnt = 0;
    for (int i = 0; i < t2; ++i)
    {
        if (cnt == a.size())
            cnt = 0;
        a[cnt]++;
        cnt++;

    }
    long long ans = a[0];
    for (int i = 1; i < a.size(); ++i)
    {
        ans *= a[i];
    }
    cout << ans;
}
