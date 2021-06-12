
#include <iostream>
#include <string>
using namespace std;
#include <deque>



int main()
{
    ios_base::sync_with_stdio(0);

    cin.tie(0);

	deque<char> dqL;
	deque<char> dqR;

    string Target;
    string str;
	string checkstr;


    cin >> Target >> str;
	string ans = "";
	while (true)
	{
		bool Left = true;
		bool find = true;
		bool Allfind = true;
		int checkLeftnum = 0;
		int checkRightnum = str.size()-1;

		for (int i=0; i<str.size(); ++i)
		{
			if (checkLeftnum > checkRightnum)
				break;
			if (Left)
			{
				dqL.push_back(str[checkLeftnum]);
				checkLeftnum++;
				if (dqL.size() >= Target.size())
				{
					for (int k = 0; k < Target.size(); ++k)
					{
						if (dqL[dqL.size()-Target.size()+k] != Target[k])
						{
							find = false;
							Allfind = false;
							break;
						}
					}

					if (find)
					{
						for (int i = 0; i < Target.size(); i++)
							dqL.pop_back();
						Left = false;
					}
					find = true;
				}
			}
			else
			{
				dqR.push_front(str[checkRightnum]);
				checkRightnum--;
				if (dqR.size() >= Target.size())
				{
					for (int k = 0; k < Target.size(); ++k)
					{
						if (dqR[k] != Target[k])
						{
							find = false;
							break;
						}
					}

					if (find)
					{
						for (int i = 0; i < Target.size(); i++)
						{
							dqR.pop_front();
							Left = true;
							Allfind = false;
						}
					}
					find = true;
				}
			}
		}


		str = "";
		for (int i = 0; i < dqL.size(); i++)
			str.push_back(dqL[i]);
		for (int i = 0; i < dqR.size(); i++)
			str.push_back(dqR[i]);

		if (Allfind == false)
			break;
	}
	if (str.find(Target)!= string::npos)
	{
		str.erase(str.find(Target), Target.size());
	}

	cout << str;
	

}
//14% 출력초과;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//왜틀려ㅠㅜㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ
