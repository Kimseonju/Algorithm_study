#include <iostream>
#include <vector>



using namespace std;


int N;
int q;
const int MAX = 100001;
vector<int> node;
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    cin >> N;
    node.resize(N + 1);
    for (int i = 1; i < N; ++i)
    {
        int start, end;
        cin >> start >> end;
        node[start]++;
        node[end]++;
    }


    int query;
    cin >> query;

    for(int i=0; i<query; ++i)
    {
        int t, k;
        cin >> t >> k;

        if (t == 1)
        {
            if (node[k] >= 2)
                cout << "yes" << '\n';
            else
                cout << "no" << '\n';
        }
        else
        {
            cout << "yes" << '\n';
        }
        
    }
}