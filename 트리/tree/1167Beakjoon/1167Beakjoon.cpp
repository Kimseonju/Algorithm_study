#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N;
vector<pair<int,int>> node[100001];
int dist[100001];
bool visit[100001];
void bfs(int start)
{
    memset(dist, 0, sizeof(dist));
    memset(visit, false, sizeof(visit));
    
    queue<int> q;
    visit[start] = true;
    q.push(start);


    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        for (int i = 0; i < node[num].size(); ++i)
        {
            int nextnode = node[num][i].first;
            int cdist = node[num][i].second;
            if (!visit[nextnode])
            {
                dist[nextnode] = cdist + dist[num];
                q.push(nextnode);
                visit[nextnode] = true;
            }
        }
    }
}

int main()
{
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int point;
        cin >> point;
        for (;;)
        {
            int a, b;
            cin >> a;
            if (a == -1)
                break;
            cin >> b;
            node[point].push_back(make_pair(a, b));
            node[a].push_back(make_pair(point, b));
        }
    }


    bfs(1);
    int start = 1;
    for (int i = 2; i <= N; i++) {
        if (dist[i] > dist[start]) {
            start = i;
        }
    }
    bfs(start);
    int ans = dist[1];
    for (int i = 2; i <= N; i++) {
        if (ans < dist[i]) {
            ans = dist[i];
        }
    }
    cout << ans;

}
