
#include <iostream>
#include <string>
#include <vector>
using namespace std;
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


string N;
int main()
{
    cin >> N;
    string ans;

    preprocessing(N);
    //bool check = false;
    //for (int i = 0; i < N.size(); ++i)
    //{
    //    if (i == 0)
    //    {
    //        ans += N[0];
    //    }
    //    if (check)
    //    {
    //        check = false;
    //        ans += N[i];
    //    }
    //    if (N[i] == '-')
    //    {
    //        check = true;
    //    }
    //}
    cout << ans;
}
