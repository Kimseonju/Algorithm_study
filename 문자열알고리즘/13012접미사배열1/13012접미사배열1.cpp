#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> suffix_array(string s) {
    vector<pair<string, int>> a;
    reverse(s.begin(), s.end());
    string cur = "";
    for (int i = 0; i < s.length(); i++) {
        cur = s[i] + cur;
        a.push_back({ cur, s.length() - i - 1 });
    }
    sort(a.begin(), a.end());
    vector<int> d;
    for (int i = 0; i < a.size(); i++) {
        d.push_back(a[i].second);
    }
    return d;
}
int main() {
    string str;
    cin >> str;
    vector<int> sa = suffix_array(str);
    int n = str.length();
    vector<int> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[sa[i]] = i;
    }
    s[n] = -1;
    vector<char> ans(n);
    char cur = 'a';
    ans[sa[0]] = cur;
    for (int i = 0; i < n - 1; i++) {
        if (s[sa[i] + 1] >= s[sa[i + 1] + 1]) {
            cur += 1;
        }
        ans[sa[i + 1]] = cur;
    }
    string ss = "";
    for (char c : ans) {
        ss += c;
    }
    if (ss < str) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
    return 0;
}