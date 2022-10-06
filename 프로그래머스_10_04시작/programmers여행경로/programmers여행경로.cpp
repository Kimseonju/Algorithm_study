/*

처음에 풀때는 모든 노드를 설정하고 정렬을 하면 된다는 식으로 풀었다.
하지만 정렬도중 두번째 세번째 알파벳도 체크해야된다는것을 알았고,
아예 처음부터 정렬을 수행한다면 이미 정렬된상태로 수행이 된다.

이 코드는 찾아갈 수 있는 모든 노드를 탐색하는 방법
더 좋은 방법은 이동할 수 있는 적절한 노드를 한번 찾아내는 것 
*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> MovesClear;
bool useTicket[999991];
bool Compare(const vector<string>& a, const vector<string>& b)
{
    bool check = false;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i][0] < b[i][0])
        {
            return true;
        }
        else if (a[i][0] == b[i][0])
            continue;
        else
        {
            return false;
        }
    }

}

void DFS(vector<string>& Move, vector<vector<string>>& tickets, string Now)
{
    bool check = false;
    for (int i = 0; i < tickets.size(); ++i)
    {
        if (!useTicket[i])
        {
            check = true;
            break;
        }
    }
    if (!check)
    {
        MovesClear.push_back(Move);
        return;
    }
    for (int i = 0; i < tickets.size(); ++i)
    {
        if (useTicket[i])
            continue;
        if (tickets[i][0] == Now)
        {
            Move.push_back(tickets[i][1]);
            useTicket[i] = true;
            DFS(Move, tickets, tickets[i][1]);
            Move.pop_back();
            useTicket[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    vector<string> Move;
    string Now = "ICN";
    Move.push_back(Now);
    sort(tickets.begin(), tickets.end());
    DFS(Move, tickets, Now);
    //sort(MovesClear.begin(), MovesClear.end(), Compare);
    return MovesClear[0];
}