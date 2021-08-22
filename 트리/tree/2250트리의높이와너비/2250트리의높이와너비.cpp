#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;


struct snode
{
    int data;
    int x;
    int level;
    snode* leftchild;
    snode* rightchild;
    snode* parent;
};

int X = 1;
void inorder(snode* node, int level)
{
    if (node->leftchild)
        inorder(node->leftchild, level + 1);

    node->x = X++;
    node->level = level;
    if (node->rightchild)
    {
        node->rightchild->x++;
        inorder(node->rightchild, level + 1);

    }
}
int sort_node(const snode& start, const snode& end) {
    if (start.level != end.level)
        return start.level < end.level;
    else
        return start.x < end.x;
}

int main()
{
    cin >> n;
    vector<snode> node(n+1);

    for (int i = 1; i <= n; ++i)
    {
        node[i].data = i;
    }
    for (int i = 0; i < n; ++i)
    {
        int start, leftchild, rightchild;
        cin >> start >> leftchild >> rightchild;
        if (leftchild != -1)
        {
            node[start].leftchild = &node[leftchild];
            node[start].leftchild->parent = &node[start];
            
        }
        if (rightchild != -1)
        {
            node[start].rightchild = &node[rightchild];
            node[start].rightchild->parent = &node[start];
        }

    }
    inorder(&node[1], 0);


    sort(node.begin() + 1, node.end(), sort_node);
    

    int answer_width = 1;
    int answer_height = 1;
    int height = -1;
    int row_first = -1;
    for (int i = 1; i <= n; i++) {
        if (height < node[i].level) {
            height++;
            row_first = i;
        }
        else if (height == node[i].level) {
            if (answer_width < node[i].x - node[row_first].x + 1) {
                answer_width = node[i].x - node[row_first].x + 1;
                answer_height = height;
            }
        }
    }


}
