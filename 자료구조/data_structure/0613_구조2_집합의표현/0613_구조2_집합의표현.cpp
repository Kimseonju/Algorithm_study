#include <iostream>

using namespace std;
int N, M;
int Parent[1000001];
int num = 1;

int Find(int x)
{
    if (x == Parent[x] || -1 == Parent[x])
        return x;
    else
        return Parent[x]=Find(Parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    Parent[y] = x;
}


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    int one, two, three;
    Parent[0]=-1;
    for (int i = 1; i <= N; ++i)
    {
        Parent[i] = i;
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> one >> two >> three;

        if (0==one)
        {
            Union(two, three);
        }

        else
        {
            if (Find(two) != Find(three))
                cout << "NO\n";
            else
                cout << "YES\n";
        }

    }
}
