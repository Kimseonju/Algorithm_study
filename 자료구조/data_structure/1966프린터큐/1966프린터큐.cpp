#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int n, m;
int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        queue<int> q;
        queue<int> qdata;
        priority_queue<int> qqsort;

        cin >> n >> m;
        for (int j = 0; j < n; ++j)
        {
            int temp;
            cin >> temp;
            qdata.push(temp);
            qqsort.push(temp);
            q.push(j);

        }
        int countt = 1;
        while (!qqsort.empty())
        {
            int check = qqsort.top();
            int data = qdata.front();
            int num = q.front();
            qdata.pop();
            q.pop();
            if (data == check)
            {
                if (m == num)
                {
                    cout << countt << '\n';
                    break;
                }
                countt++;
                qqsort.pop();
            }
            else
            {
                qdata.push(data);
                q.push(num);
            }
            
        }

    }

    
}
