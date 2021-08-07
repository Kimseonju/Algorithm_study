
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>map1;
int ans = 0;

vector<vector<pair<int, int>>> block;

int mapcheck(vector<vector<int>> v)
{
	int count = 0;
	for (int i = 0; i<v.size(); ++i)
	{
		bool check = false;
		for (int j = 0; j < v.size(); ++j)
		{
			if (v[i][j] == 0)
			{
				check = true;
				break;
			}
		}
		if (!check)
			count++;
	}
	return count;
}

int check(int blocknum, int clearnum)
{
	int mapsize = map1.size()-1;
	//가로
	for (int i = mapsize; i >= 0; --i)
	{
		//세로
		int count = 0;
		for (int j = mapsize; j >= 0; --j)
		{
			//있는지 체크하는 함수
			bool check = true;
			vector<vector<int>> checkmap = map1;
			for (int k = 0; k < block[blocknum].size(); ++k)
			{
				int x= block[blocknum][k].first;
				int y= block[blocknum][k].second;
				if (j + y > mapsize || i + x > mapsize)
				{
					check = false;
					break;
				}
					

				if (checkmap[j + y][i + x] != 0)
				{
					check = false;
					break;
				}
				else
				{
					checkmap[j + y][i + x] = 1;
				}
			}
			//만약 꼳을 수 있다면
			if (check)
			{
				ans= max(ans, mapcheck(checkmap));
			}
		}
	}
	return ans;
}


int main()
{
	vector<int>v;

	v.push_back(1);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	map1.push_back(v);
	v.clear();

	v.push_back(1);
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	map1.push_back(v);
	v.clear();

	v.push_back(1);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	map1.push_back(v);
	v.clear();

	v.push_back(1);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	map1.push_back(v);
	vector<pair<int, int>> bl;
							//x, y l
	bl.push_back(make_pair(0, 0));
	bl.push_back(make_pair(0, 1));
	bl.push_back(make_pair(0, 2));
	block.push_back(bl);
	bl.clear();
	//m
	bl.push_back(make_pair(0, 0));
	bl.push_back(make_pair(1, 0));
	bl.push_back(make_pair(2, 0));
	block.push_back(bl);
	bl.clear();
	//L
	bl.push_back(make_pair(0, 0));
	bl.push_back(make_pair(0, 1));
	bl.push_back(make_pair(1, 1));
	block.push_back(bl);
	bl.clear();
	// L역
	bl.push_back(make_pair(1, 0));
	bl.push_back(make_pair(1, 1));
	bl.push_back(make_pair(0, 1));
	block.push_back(bl);
	bl.clear();
	check(0, 0);
	//ㄱ
	bl.push_back(make_pair(0, 0));
	bl.push_back(make_pair(1, 1));
	bl.push_back(make_pair(1, 0));
	block.push_back(bl);
	bl.clear();
	check(0, 0);
	//ㄱ 역
	bl.push_back(make_pair(0, 0));
	bl.push_back(make_pair(0, 1));
	bl.push_back(make_pair(1, 0));
	block.push_back(bl);
	bl.clear();
	check(0, 0);
	cout << ans << endl;
}