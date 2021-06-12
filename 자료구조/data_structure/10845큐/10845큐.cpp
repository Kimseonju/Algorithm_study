
#include <iostream>
#include <queue>
using namespace std;
int num[10001];
int N;
int qsize = 0;
int qstart=0;
int qend=0;
int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		if ("push" == str)
		{
			int a;
			cin >> a;
			num[qend] = a;
			qsize++;
			qend++;
		}
		if ("pop" == str)
		{
			if (qsize == 0)
			{
				cout << "-1" << endl;
				continue;
			}
				
			cout << num[qstart] << endl;
			qstart++;
			qsize--;

		}
		if ("size" == str)
		{
			cout << qsize << endl;
		}
		if ("empty" == str)
		{
			if (qsize == 0)
			{
				cout << "1" << endl;
			}
			else 
			{
				cout << "0" << endl;
			}
		}
		if ("front" == str)
		{
			if (qsize == 0)
			{
				cout << "-1" << endl;
				continue;
			}
			cout << num[qstart] << endl;
		}
		if ("back" == str)
		{
			if (qsize == 0)
			{
				cout << "-1" << endl;
				continue;
			}
			cout << num[qend-1] << endl;
		}
	}


}