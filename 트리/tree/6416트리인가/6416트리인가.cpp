#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <memory.h>
#include <map>
using namespace std;
vector<int> node[100001];


int N, M;
int main()
{
    int i = 1;
    for (;;)
    {
        bool treecheck = true;
        map<int, int> tree;
        for (;;)
        {
            cin >> N >> M;

            if ((N == 0 && M == 0) || (N < 0 && M < 0))
            {
                break;
            }
            //트리만들기

            if (tree[N] == NULL)
                tree[N] = 0;
            if (tree[M] == NULL)
                tree[M] = 0;

            if (N == M)
            {
                treecheck = false;
            }
            else
            {
                tree[M]++;
            }

        }

        if (N < 0 && M < 0)
            break;
        int cnt = 0;
        for (auto treea : tree)
        {
            if (treea.second == 0 || treea.second > 1)
                cnt++;
        }

        if (tree.size()==0)
        {
            cout << "Case " << i << " is a tree." << '\n';
        }
        else if (treecheck && cnt==1)
        {
            cout << "Case " << i << " is a tree." << '\n';
        }
        else
        {
            cout << "Case " << i << " is not a tree." << '\n';
        }
        i++;

    }
}
