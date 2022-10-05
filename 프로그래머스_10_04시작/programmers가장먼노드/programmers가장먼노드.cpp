


#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int Dir[25000];
int MaxDepth = 0;
void sol(int Start, vector<vector<int>>& edge2)
{
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, Start));
    while (!pq.empty())
    {
        int Next = pq.top().second;
        int NextDepth = -pq.top().first;
        pq.pop();

        if (NextDepth > Dir[Next])
            continue;
        for (int i = 0; i < edge2[Next].size(); ++i)
        {
            if (Dir[edge2[Next][i]] > NextDepth + 1)
            {
                if (MaxDepth < NextDepth + 1)
                {
                    MaxDepth = NextDepth + 1;
                }
                Dir[edge2[Next][i]] = NextDepth + 1;
                pq.push(make_pair(-(NextDepth + 1), edge2[Next][i]));
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        Dir[i] = 50000;
    }
    vector<vector<int>> edge2;
    edge2.resize(n + 1);
    for (int i = 0; i < edge.size(); ++i)
    {
        edge2[edge[i][0]].push_back(edge[i][1]);
        edge2[edge[i][1]].push_back(edge[i][0]);
    }

    Dir[1] = 0;
    sol(1, edge2);
    for (int i = 1; i < n + 1; ++i)
    {
        if (MaxDepth == Dir[i])
        {
            answer++;
        }
    }
    return answer;
}

