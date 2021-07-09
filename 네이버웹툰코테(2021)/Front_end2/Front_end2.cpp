
#include <iostream>
#include <vector>

using namespace std;
vector<int> cost;

int ans = 0;
int maxmoney;
void resultfunc(int money, int cccost/*0층부터 시작*/, int num)
{
	if (cccost == cost.size() - 1)
	{
		ans = max(ans, num);
		return;
	}


	if (cost[cccost] == 0)
	{
		resultfunc(money, cccost + 1, num + 1);
	}

	if (cost[cccost] <= money)
	{
		int tempmoney=money - cost[cccost];
		resultfunc(tempmoney, cccost + 1, num + 1);
	}


	//안짓는다면? 층비교후 다날리기
	ans = max(ans, num-1);
	resultfunc(maxmoney, cccost + 1, 0);
}



int main()
{
	//cost.push_back(0);
	//cost.push_back(900);
	//cost.push_back(0);
	//cost.push_back(200);
	//cost.push_back(150);
	//cost.push_back(0);
	//cost.push_back(30);
	//cost.push_back(50);
	//maxmoney = 420;


	cost.push_back(245);
	cost.push_back(317);
	cost.push_back(151);
	cost.push_back(192);
	maxmoney = 100;


	resultfunc(maxmoney, 0, 0);
	cout << ans << endl;

}
