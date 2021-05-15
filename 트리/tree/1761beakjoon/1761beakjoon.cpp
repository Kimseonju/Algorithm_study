
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
vector<pair<int, int>>vnode[40001];
int visit[40001];
int dist[40001];
int parent[40001];
int depth[40001];


void lca(int start)
{
    memset(dist, 999999, sizeof(dist));

    queue<int> q;
    q.push(start);
    visit[start] = true;
    parent[start] = start;
    dist[start] = 0;
    while (!q.empty())
    {
        int inode = q.front();
        q.pop();
        for (int i = 0; i < vnode[inode].size(); ++i)
        {
            int nextnode = vnode[inode][i].first;
            int cdist = vnode[inode][i].second + dist[inode];
            if (!visit[nextnode])
            {
                if (dist[nextnode] > cdist)
                    dist[nextnode] = cdist;
                parent[nextnode] = inode;
                depth[nextnode] = depth[inode] + 1;
                q.push(nextnode);
                visit[nextnode] = true;
            }
        }
    }

}

int findparent(int one, int two)
{
    if (depth[one] < depth[two])
    {
        int temp = one;
        one = two;
        two = temp;
    }
    for (;;)
    {
        if (depth[one] == depth[two])
        {
            break;
        }
        one = parent[one];
    }
    while (one != two)
    {
        one = parent[one];
        two = parent[two];
    }
    return one;
}


int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int one, two, dist;
        cin >> one >> two >> dist;
        vnode[one].push_back(make_pair(two, dist));
        vnode[two].push_back(make_pair(one, dist));
    }

    lca(1);
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int one, two;
        cin >> one >> two;
        int k = findparent(one, two);
        int ans = dist[one] + dist[two] - (dist[k] * 2);

        cout << ans << "\n";
    }

}