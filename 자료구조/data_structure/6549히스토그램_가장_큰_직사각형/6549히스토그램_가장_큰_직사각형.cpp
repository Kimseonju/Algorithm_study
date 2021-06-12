#include <iostream>
#include <deque>
using namespace std;

int N;
long long Rects[100001];
int main()
{
    long long ans = 0;

    for (;;)
    {
        cin >> N;
        if (N == 0)
            break;
        for (int i = 0; i < N; ++i)
        {
            cin >> Rects[i];
        }

        deque<long long> dq;
        for (int i = 0; i < N; ++i)
        {
            long long Left = i;
            while (!dq.empty() && Rects[dq.back()] > Rects[i])
            {
                long long height = Rects[dq.back()];
                dq.pop_back();
                long long width = i;
                if (!dq.empty())
                    width = (i - dq.back() - 1);
                if (ans < width * height)
                    ans = width * height;
            }

            dq.push_back(i);
        }
        while (!dq.empty()) {
            long long height = Rects[dq.back()];
            dq.pop_back();
            long long width = N;
            if (!dq.empty()) {
                width = N - dq.back() - 1;
            }
            if (ans < width * height) {
                ans = width * height;
            }
        }

            
        cout << ans<<endl;
        ans = 0;


    }
}
