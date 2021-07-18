#include <iostream>
#include <vector>
using namespace std;

vector<int> preprocessing(int l, string p) {
    vector<int> pi(l, 0);
    int j = 0;
    for (int i = 1; i < l; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
        {
            pi[i] = j + 1;
            j++;
        }
    }
    return pi;
}
int main()
{
    int l;
    cin >> l;
    string p;
    cin >> p;

    vector<int> ans = preprocessing(l, p);

    cout << l - ans[l - 1];
}