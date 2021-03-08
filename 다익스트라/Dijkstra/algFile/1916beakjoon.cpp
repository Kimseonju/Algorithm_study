// 1916beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
class bus_stop {
public:
	int node;
	int dir;

	bus_stop(int a, int direction)
	{
		node = a;
		dir = direction;
	}
};
int N, M;
int startN, endN;
vector<bus_stop>v[1001];
int number[1001];
queue<int> pq;
vector <int> path[1001];
void Dijkstra(int start)
{
	pq.push(start);
	number[start] = 0;
	path[start].push_back(start+1);
	while (!pq.empty()) {
		int num = pq.front();
		pq.pop();
		for (int i = 0; i < v[num].size(); i++) {

			if (number[num] + v[num][i].dir < number[v[num][i].node]) {
				number[v[num][i].node] = number[num] + v[num][i].dir;
				vector <int> temp_v;
				temp_v = path[num];
				temp_v.push_back(v[num][i].node+1);
				path[v[num][i].node] = temp_v;
				pq.push(v[num][i].node);
			}
		}
	}
}
int main()
{

	cin >> N;
	cin >> M;
	int a, b, c;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b >> c;
		v[a-1].push_back(bus_stop(b-1, c));
	}
	for (int i = 0; i < N; ++i)
	{
		number[i] = 1000000000;
	}
	cin >> startN;
	startN--;
	number[startN] = 0;
	cin >> endN;
	Dijkstra(startN);
	
	cout << number[endN - 1]<<"\n";
	cout << path[endN - 1].size() << '\n';
	for (auto it : path[endN-1]) {
		cout << it << ' ';
	}

}

