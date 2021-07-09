
#include <iostream>
#include <vector>

using namespace std;


vector<int>dollarDay;

int dps(int day, int money, bool dollar)
{
	int m1 = 0, m2 = 0, m3=0;
	if (day == dollarDay.size()-1)
	{
		if (dollar)
			money += dollarDay[day];
		return money;
	}
		


	if (dollarDay[day] <= money)
	{
		if (!dollar)
		{
			//구매하고 넘기기
			m2=dps(day+1, money - dollarDay[day], true);
		}
	}
	if (dollar)
	{
		m3 = dps(day + 1, money +dollarDay[day], false);
	}

	//구매안하고 넘기기
	m1 = dps(day + 1, money, dollar);

	return max(m1, max(m2,m3));

}

int main()
{
	//dollarDay.push_back(1200);
	//dollarDay.push_back(1000);
	//dollarDay.push_back(1100);
	//dollarDay.push_back(1200);
	//dollarDay.push_back(900);
	//dollarDay.push_back(1000);
	//dollarDay.push_back(1500);
	//dollarDay.push_back(900);
	//dollarDay.push_back(750);
	//dollarDay.push_back(1100);

	dollarDay.push_back(1500);
	dollarDay.push_back(1400);
	dollarDay.push_back(1300);
	dollarDay.push_back(1200);

	int num=dps(0, 1500, false);

}
