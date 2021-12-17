#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

// N 叉树的定义
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// 递归法
int maxdepth(Node *root)
{
    if (root == 0)
        return 0;
    int depth = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        depth = max(depth, maxdepth(root->children[i]));
    }
    return depth + 1;
}

// 层次遍历法
int maxDepthLevelOrder(Node *root)
{
    queue<Node *> que;
    int depth = 0;
    if (root != NULL)
    {
        que.push(root);
    }

    while (!que.empty())
    {
        int size = que.size();
        depth++;
        for (int i = 0; i < size; i++)
        {
            Node *node = que.front();
            que.pop(); // 先弹出队列中的一个节点。
            for (int j = 0; j < node->children.size() ; j++)
            {
                if (node->children[j])
                {
                    que.push(node->children[j]);
                }
            }
        }
    }
    return depth;
}

int main()
{
    vector<Node *> child1;
    vector<Node *> child2;

    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    child2.push_back(node4);
    child2.push_back(node5);

    Node *node1 = new Node(1, child2);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);

    child1.push_back(node1);
    child1.push_back(node2);
    child1.push_back(node3);

    Node *root = new Node(1, child1);

    cout << maxDepthLevelOrder(root) << endl;

    system("pause");
    return 0;
}
