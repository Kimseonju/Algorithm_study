#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;
vector<vector<int>> vstr;
vector<vector<int>> vstr1;
int N, S, E;
long long int T;
int ans = 0;
//https://fullalgorithmpanic.blogspot.com/2016/09/boj-1533.html
//중첩해주면은 시간을
//
//시간초과가 나서 제곱을 행렬제곱을 이용해서 구해야 하는 문제인데요
//어떤정점에서 어떤정점까지있는데 이 문제에서 A라는 행렬에 입력되는 값이 가중치를 구해줘서나타내는데
//그렇게 하면은 시간초과가 난다고 해서 쪼개는것이다.
//그래서 문제에서 최대 가중치가 5니까 5개로 나눠서 가중치가 1인 연결이 되있는지 안되있는지 하고
//정점이 다른정점으로 갈떄 1초인가 1인가 1의 시간만 걸린다고 하고, 최대 5니까 한정점에서 다음정점까지 넘어간느것을 5개로 쪼개서 해주는것 ?
//
//그래서 제가 올린 코드를 설명을 하면은
//operator*는 행렬의 곱 구현 입력을 다 받은 다음에 이걸 그냥 가중치를 따로 나타내지않고 정점끼리 연결이 되있다는것만 생각을 하면서 한 정점당 시간 하나당 정점을 5개로 나눠서 처음에
//입력받은 n에서 5개로 나눠줘서 예를들어서 1번에서 2번으로 갈때 3의 시간이ㅣ 걸렸다면은 A배열 1, 2가 3이되야하는데 1 - 1, 1 - 2, 1 - 3에서 2 - 1로 가도록 구현을 되어있는것 같다.
//그래서 네임 중간에 A백터를 초기화를 해준 부분이 5개로 쪼개서 연결을 해주는것을 표현을 해줬고,
//인접행렬을 A백터를 갱신을 해준것은 쪼깨졌던것을 구해준다고 그 뒤의 루프문은 입력을 받은 다음에 입력받은갑ㅄ을 토대로 다른 정점을 연결하는것을 구현해준것같다.
//그다음 행렬곱을 한게 블로그에서 보면은 제곱행렬 N곱을 이용할떄 I에서 J의 경로를 알수있다.경로의 개수를 구해준 것같다.


void dp(int location, long long int time)
{
    if (time > T)
    {
        return;
    }
    else if (time == T)
    {
        if (location == E-1)
        {
            ans++;
        }
        return;
    }
    //0부터 3까지(2까지)
    for (int i = 0; i < E; ++i)
    {
        int NextTime=vstr[location][i]-'0';
        if (NextTime == 0)
            continue;
        dp(i, NextTime+ time);
    }
}


void procession()
{
    //세로
    for (int i = 0; i < vstr.size(); ++i)
    {
        int sum = 0;
        //가로
        for (int j = 0; j < vstr[i].size(); ++j)
        {
            //곱셈
            int sum=0;
            for (int k = 0; k < vstr.size(); ++k)
            {
                int a = vstr[i][k];
                int b = vstr[k][j];
                int c = a * b;
                sum += c;
            }

            vstr1[i][j] = sum;
        }
    }
}
int main()
{
    cin >> N >> S >> E >> T;

    
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        vector<int>v;
        for (int i = 0; i < str.size(); ++i)
        {
            int a = str[i] - '0';
            v.push_back(a);
        }
        vstr.push_back(v);
    }
    vstr1 = vstr;
    procession();

    dp(0, 0);
    cout << ans % 1000003;
}
