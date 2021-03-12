// 1916beakjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <string>
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
int numcount[1001];
int route[1001];
int dis = 0;
queue<int> pq;
void Dijkstra(int start)
{
	pq.push(start);
	number[start] = 0;
	while (!pq.empty()) {
		int num = pq.front();
		pq.pop();
		for (int i = 0; i < v[num].size(); i++) {

			if (number[num] + v[num][i].dir < number[v[num][i].node]) {
				number[v[num][i].node] = number[num] + v[num][i].dir;

				route[v[num][i].node] = num;

				dis = v[num][i].node;
				numcount[num]++;
				numcount[v[num][i].node] = numcount[num];

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
		v[a - 1].push_back(bus_stop(b - 1, c));
	}
	for (int i = 0; i < N; ++i)
	{
		number[i] = 1000000000;
		route[i] = 100001;
	}
	cin >> startN;
	startN--;
	cin >> endN;
	

	Dijkstra(startN);

	cout << number[endN - 1]<<"\n" << numcount[endN - 1];
	int temp = 100;
	for (int i = 0; i < N; ++i)
	{

	}
}
