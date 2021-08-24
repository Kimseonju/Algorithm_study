

#include <iostream>
#include <vector>
using namespace std;
int x, y;
int map[1025][1025];
int dp[1025][1025];

int main()
{
    cin >> x >> y;
    vector<int> v;
    for (int i = 0; i < y; ++i)
    {
        for(int j=0; j<x; ++j)
        {
            cin >> map[i][j];
        }
    }
    dp[0][0] = map[0][0];
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            int left = 0; 
            int up = 0;
            if(j-1>=0)
                left = map[i][j - 1];
            if (i - 1 >= 0)
                up = map[i - 1][j];
            map[i][j] = map[i][j - 1] + map[i - 1][j];

        }
    }
    int b = 0;

}