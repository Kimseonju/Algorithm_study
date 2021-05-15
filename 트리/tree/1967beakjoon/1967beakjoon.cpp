#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N;
vector<pair<int,int>> node[10001];
int dist[10001];
bool visit[10001];
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
	for (int i = 0; i < N - 1; ++i)
	{
		int parent, child, indist;
		cin >> parent >> child >> indist;
		node[parent].push_back(make_pair(child, indist));
        node[child].push_back(make_pair(parent, indist));
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
