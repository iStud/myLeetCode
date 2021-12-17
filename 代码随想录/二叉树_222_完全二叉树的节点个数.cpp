#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int getNodesNumLevalOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int num = 0;
    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {

        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            num++;

            if (node->left)
            {
                que.push(node->left);
            }

            if (node->right)
            {
                que.push(node->right);
            }
        }
    }
    return num;
}

int getNodesNum(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftNum = getNodesNum(root->left);
    int rightNum = getNodesNum(root->right);
    return leftNum + rightNum + 1;
}

int main()
{
    TreeNode *node0 = new TreeNode;
    node0->val = 3;

    TreeNode *node1 = new TreeNode;
    node1->val = 9;

    TreeNode *node2 = new TreeNode;
    node2->val = 20;

    TreeNode *node3 = new TreeNode;
    node3->val = 15;

    TreeNode *node4 = new TreeNode;
    node4->val = 7;

    node0->left = node1;
    node0->right = node2;

    node1->left = NULL;
    node1->right = NULL;

    node2->left = node3;
    node2->right = node4;

    node3->left = NULL;
    node3->right = NULL;

    node4->left = NULL;
    node4->right = NULL;

    cout << getNodesNumLevalOrder(node0) << endl;

    system("pause");
    return 0;
}
