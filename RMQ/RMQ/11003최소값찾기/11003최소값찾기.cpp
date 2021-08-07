
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n, l;
int a[5000000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }


    deque<pair<int, int>> d;
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        if (!d.empty() && d.front().second <= i - l) {
            d.pop_front();
        }
        while (!d.empty() && d.back().first > cur) {
            d.pop_back();
        }
        d.push_back(make_pair(cur, i));
        ans[i] = d.front().first;
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", ans[i]);
    }
}