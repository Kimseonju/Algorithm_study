#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Node
{
    bool valid;
    int children[26];
    Node()
    {
        valid = false;
        for (int i = 0; i < 26; i++) {
            children[i] = -1;
        }
    }
};
vector<Node> trie;
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int score_[] = { 0,0,0,1,1,2,3,5,11 };
bool check[4][4];


int init()
{
    Node x;
    trie.push_back(x);
    return (int)trie.size() - 1;
}

void add(int node, string& s, int index) {
    if (index == s.size()) 
    {
        trie[node].valid = true;
        return;
    }
    int c = s[index] - 'A';
    if (trie[node].children[c] == -1) {
        int next = init();
        trie[node].children[c] = next;
    }
    add(trie[node].children[c], s, index + 1);
}

void triefind(int node, int x, int y, string checkstr, vector<string>& board, vector<string>& word)
{
    if (x < 0 || y < 0 || x >= 4 || y >= 4)
        return;

    if (check[x][y])
        return;

    if (checkstr.size() == 8)
        return;

    check[x][y] = true;
    int c = board[x][y] - 'A';
    int next = trie[node].children[c];
    if (next == -1)
    {
        check[x][y] = false;
        return;
    }
        
    checkstr += board[x][y];
    //마지막글자
    if (trie[next].valid)
    {
        word.push_back(checkstr);
    }

    for (int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        triefind(next, nx, ny, checkstr, board, word);
    }
    check[x][y] = false;
}

int w, b;
int main()
{
    cin >> w;
    string str;
    int root = init();
    for (int i = 0; i < w; ++i)
    {
        cin >> str;
        add(root, str, 0);
    }
    cin >> b;

    
    for (int i = 0; i < b; ++i)
    {
        vector<string>board;
        vector<string>word;
        for (int j = 0; j < 4; ++j)
        {
            cin >> str;
            board.push_back(str);
        }
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                triefind(root, i, j, "", board, word);
            }
        }

        sort(word.begin(), word.end());
        word.erase(unique(word.begin(), word.end()), word.end());

        int ans = 0;
        int cnt = 0;
        string ansstr;
        for (int i = 0; i < word.size(); ++i)
        {
            ans += score_[word[i].size()];
            if (ansstr.size() < word[i].size())
            {
                ansstr = word[i];
            }
            else if (ansstr.size() == word[i].size() && ansstr > word[i])
                ansstr = word[i];
        }
        cout << ans << ' ' << ansstr << ' ' << word.size() << '\n';
    }
}
