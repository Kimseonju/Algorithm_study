#include <iostream>

using namespace std;

int a[100001];
int tree[300001];
int tree2[300001];

void init(int node, int start, int end)
{

    if (start == end)
    {
        tree[node] = a[start];
    }

    else
    {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);

        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);

    }
}
void init2(int node, int start, int end)
{

    if (start == end)
    {
        tree2[node] = a[start];
    }

    else
    {
        init2(node * 2, start, (start + end) / 2);
        init2(node * 2 + 1, (start + end) / 2 + 1, end);

        tree2[node] = max(tree2[node * 2], tree2[node * 2 + 1]);

    }
}

int query(int node, int start, int end, int i, int j) {
    if (i > end || j < start) return -1;
    if (i <= start && end <= j) return tree[node];

    int m1 = query(2 * node, start, (start + end) / 2, i, j); // 왼쪽
    int m2 = query(2 * node + 1, (start + end) / 2 + 1, end, i, j); // 오른쪽

    if (m1 == -1) return m2;
    else if (m2 == -1) return m1;
    else return min(m1, m2);
}

int query2(int node, int start, int end, int i, int j) {
    if (i > end || j < start) return -1;
    if (i <= start && end <= j) return tree2[node];

    int m1 = query2(2 * node, start, (start + end) / 2, i, j); // 왼쪽
    int m2 = query2(2 * node + 1, (start + end) / 2 + 1, end, i, j); // 오른쪽

    if (m1 == -1) return m2;
    else if (m2 == -1) return m1;
    else return max(m1, m2);
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int start_range;
    int end_range;


    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    init(1, 0, n - 1);
    init2(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        scanf("%d", &start_range);
        scanf("%d", &end_range);


        int ans = query(1, 0, n - 1, start_range - 1, end_range - 1);
        int max2 = query2(1, 0, n - 1, start_range - 1, end_range - 1);

        printf("%d %d\n", ans, max2);

    }
}
