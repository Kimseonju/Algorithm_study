#include <iostream>



using namespace std;
int n, m;
long long int map[1300][1300];
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);


    cin >> n >> m;
    //i=y j=x
    int temp = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> temp;
            map[i][j] = map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1] + temp;
        }
    }
    int x1, y1, x2, y2;
    long long int ans;
    for (int i = 0; i < m; ++i)
    {
        //42-
        cin >> x1 >> y1 >> x2 >> y2;

        ans = map[x2][y2] - map[x1 -1][y2] -map[x2][y1 -1]+map[x1 -1][y1 -1];
        cout << ans << "\n";
    }

}
