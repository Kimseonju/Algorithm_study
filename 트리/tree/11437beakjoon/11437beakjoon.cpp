//트리2 LCA
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
vector<int> node[50001];
vector<int>vec;
int parent[50001];
int visit[50001];
int depth[50001];
void bfs(int start)
{
    visit[start] = true;
    queue<int> q;
    q.push(start);
    parent[start] = start;
    while (!q.empty())
    {
        int inode=q.front();
        q.pop();
        for (int i = 0; i < node[inode].size(); ++i)
        {
            int nextnode = node[inode][i];
            if (!visit[nextnode])
            {
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
    for (int i = 0; i < N-1; ++i)
    {
        int left, right;
        cin >> left >> right;
        node[left].push_back(right);
        node[right].push_back(left);
    }

    bfs(1);

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int left, right;
        cin >> left >> right;
        int k=findparent(left, right);
        cout << k << "\n";
    }

    
}
