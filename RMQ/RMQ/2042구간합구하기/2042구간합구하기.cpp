#include <iostream>
using namespace std;

int n, m, k;

long long ma[1000001];
long long tree[3000001];

long long init(int node, int start, int end)
{
    if (start == end)
    {
        return tree[node] = ma[start];
    }

    else
    {
       int mid = (start + end) / 2;
       return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);

    }
}

long long sum(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)return 0;

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right)+ sum(node * 2+1, mid+1, end, left, right);
}
    
void update(int node, int start, int end, int index, long long dif)
{
    if (index<start || index>end) return;

    tree[node] += dif;
    if (start == end)return;

    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, dif);
    update(node * 2 + 1, mid + 1, end, index, dif);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
    {
        cin >> ma[i];
    }

    init(1, 0, n);
    int a = 0, b = 0;
    long long c = 0;
    for (int i = 0; i < m + k; ++i)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            long long int temp = c- ma[b] ;
            ma[b] = c;
            update(1, 0, n, b, temp);
        }
        else if (a == 2)
        {
            cout << sum(1,0, n, b, c) << "\n";
        }
    }
}
