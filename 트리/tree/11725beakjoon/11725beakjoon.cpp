#include <iostream>
#include <vector>
using namespace std;
int N;

vector<int> nnode[100001];
int parent[100001];
bool visit[100001];
void findParent(int num)
{
    visit[num] = true;

    for (int i = 0; i < nnode[num].size(); ++i)
    {
        int next = nnode[num][i];
        if (!visit[next])
        {
            parent[next] = num;
            findParent(next);
        }
    }
}
int main()
{
    cin >> N;

    for (int i = 0; i < N-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        nnode[a].push_back(b);
        nnode[b].push_back(a);
    }
    findParent(1);
    for (int i = 2; i <= N; i++)
        cout << parent[i] << "\n";

    return 0;
}
