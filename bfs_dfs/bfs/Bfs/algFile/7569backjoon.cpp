#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, H;
int insert;
int day = 0;
int map[101][101][101] = { -1 };
bool visit[101][101][101] = { false };
queue<pair<pair<int, int>, int>> q;
int dm[] = { -1,1,0,0,0,0 };
int dn[] = { 0,0,0,0,-1,1 };
int dh[] = { 0,0,-1,1,0,0 };
int main()
{
	cin >> M >> N >> H;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				cin >> map[i][j][k];
				if (map[i][j][k] == 1){
					visit[i][j][k] = true;
					q.push({ { k,j }, i });
				}
				if (map[i][j][k] == -1)
					visit[i][j][k] = true;
			}
		}
	}//높이 세로 가로

	int day = 0;
	for (;;)
	{
		int qCount = q.size();
		for(int i=0; i< qCount; ++i){
			int pm=q.front().first.first;
			int pn = q.front().first.second;
			int ph = q.front().second;
			q.pop();

			for (int l = 0; l < 6; ++l) {
				int chm = pm + dm[l];
				int chn = pn + dn[l];
				int chh =ph + dh[l];
				if (chm >= 0 && chm < M && chn>=0 && chn < N && chh>=0 && chh < H)
				{
					if ((!visit[chh][chn][chm]) && map[chh][chn][chm] == 0)
					{
						visit[chh][chn][chm] = true;
						map[chh][chn][chm] = 1;
						q.push({ { chm,chn }, chh });
					}
				}
			}
		}
		if (q.size() == 0)
			break;
		day++;
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (map[i][j][k] == 0){
					cout << "-1";
					return 0;
				}
				
			}
		}
	}
	cout << day;
	return 0;
}












//int M, N, H;
////백터는 반대 H,N,M
//vector<vector<vector<int>>> vec_map;
//int insert;
//int ripe_count = 0;
//int all_count = 0;
//bool ripe_play = 0;
//int day = 0;
//int map[101][101][101] = { 0 };
//bool visit[101][101][101] = { false };
//
//int dm[] = { -1,1,0,0,0,0 };
//int dn[] = { 0,0,0,0,-1,1 };
//int dh[] = { 0,0,-1,1,0,0 };
//
//int main()
//{
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	cin >> M >> N >> H;
//	vec_map.resize(H + 1);
//	for (int i = 0; i < H; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			for (int k = 0; k < M; ++k)
//			{
//				cin >> map[i][j][k];
//				if (map[i][j][k] == 1){
//					visit[i][j][k] = true;
//					vec_map[i][j].push_back(k);
//				}
//				if (map[i][j][k] != -1)
//					visit[i][j][k] = true;
//			}
//		}
//	}//높이 세로 가로
//	int day = 0;
//	for (;;)
//	{
//		if (vec_map.size() == 0)
//			break;
//		
//		int pm, pn, ph;
//		for (int i = 0; ; ++i)
//		{
//			if (i < vec_map.size())
//				break;
//
//			for (int j = 0; ; ++j)
//			{
//				if (j < vec_map[i].size())
//					break;
//				for (int k = 0;; ++k)
//				{
//					if (k < vec_map[i][j].size())
//						break;
//
//					pm = k;
//					pn = j;
//					ph = i;
//					vec_map[i][j].back();
//					for (int l = 0; l < 6; ++l) {
//						pm + dm[l];
//						pn + dn[l];
//						ph + dh[l];
//						if (pm > 0 || pm < M || pn>0 || pn < N || ph>0 || ph < H) continue;
//
//						if (!visit[ph][pn][pm] || map[ph][pn][pm] == 0)
//						{
//							visit[ph][pn][pm] = true;
//							vec_map[ph][pn].push_back(pm);
//						}
//
//					}
//				}
//			}
//		}
//		
//		day++;
//	}
//
//
//
//	int kkkk = 0;
//}
