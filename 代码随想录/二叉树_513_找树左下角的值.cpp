#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int findBottomLeftValue(TreeNode *root)
{
    queue<TreeNode *> que;
    if (root != NULL)
    {
        que.push(root);
    }

    int result = 0;
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            if (i == 0)
            {
                result = node->val;
            }

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

    return result;
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 1;

    TreeNode *node1 = new TreeNode;
    node1->val = 2;

    TreeNode *node2 = new TreeNode;
    node2->val = 3;

    root->left = node1;
    root->right = node2;

    cout << findBottomLeftValue(root) << endl;

    system("pause");
    return 0;
}
