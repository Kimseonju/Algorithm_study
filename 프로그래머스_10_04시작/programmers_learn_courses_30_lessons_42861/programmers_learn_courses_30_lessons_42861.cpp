#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>> a;
int Link[100];
void dijkstra()
{
    priority_queue<pair<int, int>>pq;
    for (int i = 0; i < a[0].size(); ++i)
    {
        pq.push(make_pair(-a[0][i].second, a[0][i].first));
    }
    while (!pq.empty())
    {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (Link[current] < 99999999)
            continue;
        Link[current] = distance;
        for (int i = 0; i < a[current].size(); ++i)
        {
            int next = a[current][i].first;
            int nextdistance =  a[current][i].second;
            if (nextdistance < Link[next])
            {
                pq.push(make_pair(-nextdistance, next));
            }
        }
    }
}

int main()
{
    int n = 7;

    vector<vector<int>> costs;
    costs.push_back({ 2,3,7 });
    costs.push_back({ 3, 6, 13 });
    costs.push_back({ 3, 5, 23 });
    costs.push_back({ 5, 6, 25 });
    costs.push_back({ 0, 1, 29 });
    costs.push_back({ 1, 5, 34 });
    costs.push_back({ 1, 2, 35 });
    costs.push_back({ 4, 5, 53 });
    costs.push_back({ 0, 4, 75 });

    int answer = 0;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        Link[i] = 99999999;
    Link[0] = 0;

    for (int i = 0; i < costs.size(); ++i)
    {
        a[costs[i][0]].emplace_back(costs[i][1], costs[i][2]);
        a[costs[i][1]].emplace_back(costs[i][0], costs[i][2]);
    }
    dijkstra();

    for (int i = 0; i < n; ++i)
        answer += Link[i];
    return answer;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
