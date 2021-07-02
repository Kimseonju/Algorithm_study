
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


int sizex;
int m, n;

vector<int> M;
vector<int> N;
int main()
{
    cin >> sizex;

    cin >> m >> n;
    int num;
    for (int i = 0; i < m; ++i)
    {
        cin >> num;
        M.push_back(num);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        N.push_back(num);
    }
    vector<int> arr1;
    vector<int> arr2;
    vector<int> arr3;

    for (int i = 0; i < m; ++i)
    {
        int temp=0;
        temp += M[i];
        arr1.push_back(temp);
        int checki = i;
        checki--;
        if (checki < 0)
            checki = m-1;
        for (int j = i + 1; j != checki; ++j)
        {
            if (j == m)
            {
                j = -1;
                continue;
            }
            temp += M[j];
            arr1.push_back(temp);
        }
    }
    int sum=0;
    for (int i = 0; i < m; ++i)
    {
        sum += M[i];
    }
    arr1.push_back(sum);


    for (int i = 0; i < n; ++i)
    {
        int temp = 0;
        temp += N[i];
        arr2.push_back(temp);
        int checki = i;
        checki--;
        if (checki < 0)
            checki = n - 1;
        for (int j = i + 1; j != checki; ++j)
        {
            if (j == n)
            {
                j = -1;
                continue;
            }
            temp += N[j];
            arr2.push_back(temp);
        }
    }
    sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += N[i];
    }
    arr2.push_back(sum);

    int ans = 0;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for (auto item : arr1)
    {
        int diff = sizex - item;
        int ub = upper_bound(arr2.begin(), arr2.end(), diff) - arr2.begin();
        int lb = lower_bound(arr2.begin(), arr2.end(), diff) - arr2.begin();
        ans += (ub - lb);
        if (diff == 0)
            ans++;
    }


    cout << ans;
}
