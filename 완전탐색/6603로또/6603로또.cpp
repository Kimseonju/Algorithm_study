#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
int k;
int main()
{
	for (;;)
	{
		cin >> k;
		if (k == 0)
			break;
		vector<int> s(k);
		vector<int>d;
		for (int i = 0; i < k; ++i)
		{
			cin >> s[i];
		}

		
		for (int i = 0; i < k - 6; ++i)
		{
			d.push_back(0);
		}
		for (int i = 0; i < 6; ++i)
		{
			d.push_back(1);
		}

		vector<vector<int>> ans;
		do {
			vector<int> current;
			for (int i = 0; i < k; i++) {
				if (d[i] == 1) {
					current.push_back(s[i]);
				}
			}
			ans.push_back(current);
		} while (next_permutation(d.begin(), d.end()));
		sort(ans.begin(), ans.end());
		for (auto& v : ans) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}
