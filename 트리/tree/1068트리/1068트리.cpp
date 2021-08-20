#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
vector<int> vec[50];
int N, Root;
void dfs(int n)
{
	//cut아래에있는 자식노드 싹다 날리기
	if (vec[n].size() == 0)
	{
		vec[n].push_back(-2);
		return;
	}
	for (int i = 0; i < vec[n].size(); ++i)
	{

		dfs(vec[n][i]);
	}
}

int main()
{
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num== -1)
		{
			Root = i;
		}
		else
		{
			vec[num].push_back(i);
		}
	}

	int cut;
	cin >> cut;

	dfs(cut);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == cut)
				vec[i].erase(vec[i].begin() + j);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		if (vec[i].size() == 0)
			ans++;
	cout << ans << endl;

}