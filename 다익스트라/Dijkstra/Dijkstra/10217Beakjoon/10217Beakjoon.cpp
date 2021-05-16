#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, M, K;

int main()
{
    cin >> T;

    for (int num = 0; num < T; ++num)
    {
        cin >> N >> M >> K;

        vector<pair<int, pair<int, int>>>vTicket[101];
        vector<vector<int>>dist;
        dist.assign(N + 1, vector<int>(M + 1, 987654321));

        for (int Ticket = 0; Ticket < K; ++Ticket)
        {
            int start, end, cost, Timer;
            cin >> start >> end >> cost >> Timer;
            vTicket[start].push_back(make_pair(Timer, make_pair(cost,end)));
        }
        int start = 1;
        int end = N;

             //노드, 가중치, 타임
        dist[start][0] = 0; //TImer  cost node
        priority_queue<pair<int, pair<int,int>>>pq;
        pq.push(make_pair(0, make_pair(0,start)));

        while (!pq.empty())
        {
            int StartNode = pq.top().second.second;
            int NodeCost =  -pq.top().second.first;
            int NodeTimer = -pq.top().first;
            pq.pop();

            for (int i = 0; i < vTicket[StartNode].size(); ++i)
            {
                int NextNode = vTicket[StartNode][i].second.second;
                int NextCost = vTicket[StartNode][i].second.first+NodeCost;
                int NextTimer = vTicket[StartNode][i].first+NodeTimer;

                //금액이 넘지않으면
                if (M>=NextCost)
                {
                    //시간이 더 적게들면
                    if (dist[NextNode][NextCost] > NextTimer)
                    {
                         dist[NextNode][NextCost] = NextTimer;
                        pq.push(make_pair(-dist[NextNode][NextCost], make_pair(-NextCost, NextNode)));
                    }

                }
               
            }
        }
        int ans = 987654321;
        for (int i = 0; i <= M; ++i)
        {
            if (ans > dist[N][i])
                ans = dist[N][i];
        }
        if (ans == 987654321)
        {
            printf("Poor KCM\n");
        }
        else
        printf("%d\n", ans);
    }

}
