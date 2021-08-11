#include <iostream>
#include <queue>
using namespace std;

struct Pos
{
    int x;
    int y;

    Pos() : x(0), y(0) {}

    Pos(int _x, int _y) :x(_x), y(_y) {}
}; 

const int movex[4]{ 0,1,-1,0 };
const int movey[4]{ 1,0,0,-1 };
int x, y;
int Map[101][101];
int d[101][101];
int main()
{
    cin >> x >> y;

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {   
            scanf("%1d", &Map[i][j]);
            d[i][j] = 99999999;
        }
    }

    queue<Pos> q;
    q.push(Pos(0, 0));
    d[0][0] = 0;
    while (!q.empty())
    {
        Pos pos = q.front();
        q.pop();


         for (int i = 0; i < 4; ++i)
        {
            
            Pos checkpos = Pos(pos.x + movex[i], pos.y + movey[i]);

            if (checkpos.x<0 || checkpos.x>=x || checkpos.y<0 || checkpos.y>=y)
                continue;
            if (Map[checkpos.y][checkpos.x]==1)
            {

                if (d[checkpos.y][checkpos.x] > d[pos.y][pos.x]+1)
                {
                    d[checkpos.y][checkpos.x] = d[pos.y][pos.x] + 1;
                    q.push(checkpos);
                }
            }
            else
            {

                if (d[checkpos.y][checkpos.x] > d[pos.y][pos.x])
                {

                    d[checkpos.y][checkpos.x] = d[pos.y][pos.x] ;
                    q.push(checkpos);
                }
            }
                
        }

        
    }

    cout << d[y - 1][x - 1];


}
