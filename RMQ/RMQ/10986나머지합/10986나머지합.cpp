#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int a[1000001];
long long int c[1000001];


int N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    long long int sum = 0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
        sum += a[i];
        c[sum % M]++;
    }
    long long int ans = 0;
    ans += c[0];
    for (int i = 0; i < M; ++i)
    {
        if (c[i] < 2)
            continue;
        ans += (c[i]*(c[i]-1))/2;
    }
    cout << ans;
}
