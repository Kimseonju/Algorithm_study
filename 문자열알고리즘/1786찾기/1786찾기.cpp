

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string T, P;
int Tsize, Psize;

vector<int> preprocessing(string p) {
    int m = p.size();
    vector<int> pi(m);
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = j + 1;
            j += 1;
        }
        else {
            pi[i] = 0;
        }
    }
    return pi;
}
int main()
{
    
    getline(cin, T);
    getline(cin, P);

    auto vcheck=preprocessing(P);

    int a = 0;
    int temp = 0;
    int anscheck=0;
    string ans;
    Tsize = T.size();
    Psize = P.size();
    int j = 0;
    for (int i = 0; i < Tsize; ++i)
    {
       while (j > 0 && T[i] != P[j])
       {
           j = vcheck[j - 1];
       }
       if (T[i] == P[j])
       {
           if (j == Psize - 1)
           {
               anscheck++;
               ans += to_string(i + 1-j) + " ";
               j = vcheck[j];
           }
           else
           {
               j += 1;
           }
       }
    }

    //for (int i = 0; i < Tsize; )
    //{
    //    int count = 0;
    //    bool check = false;
    //
    //    for (int j = 0; j < Psize; ++j)
    //    {
    //        if (T[i+j] == P[j])
    //        {
    //            count++;
    //        }
    //        else
    //        {
    //            if (count >= checknum)
    //            {
    //                i += checknum;
    //                if(checknum!=0)
    //                    check = true;
    //            }
    //            break;
    //        }
    //        if (count == P.size())
    //        {
    //            anscheck++;
    //            ans += to_string(i+1) + " ";
    //        }
    //        
    //    }
    //
    //    if(!check)
    //        ++i;
    //}

    cout << anscheck << "\n";
    if(anscheck!=0)
        cout << ans;

}

