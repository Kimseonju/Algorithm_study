


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int city[11][11];

int N;
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> city[i][j];
        }
    }

    vector<int> d;
    for (int i = 0; i < N; ++i)
        d.push_back(i);

    int ans = 2147483647;
    do
    {
        bool check = true;
        int sum = 0;

        //백터는 순열로 돌고있다
        for (int i = 0; i < N - 1; ++i)
        {
            if (city[d[i]][d[i + 1]] == 0)
            {
                check = false;
            }
            else
            {
                sum += city[d[i]][d[i + 1]];
            }
        }
        //출발지로 돌아갈때
        if (check && city[d[N - 1]][d[0]] != 0) {
            sum += city[d[N - 1]][d[0]];
            if (ans > sum) 
                ans = sum;
        }


    } while (next_permutation(d.begin(), d.end()));
    cout << ans;
}
