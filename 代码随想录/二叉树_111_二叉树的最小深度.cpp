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

int minDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL)
    {
        return minDepth(root->right) + 1;
    }
    else if (root->right == NULL)
    {
        return minDepth(root->left) + 1;
    }
    else
    {
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
}

int minDepthLevelOrder(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int depth = 0;
    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        int size = que.size();
        depth++;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();

            if (node->left)
            {
                que.push(node->left);
            }

            if (node->right)
            {
                que.push(node->right);
            }
            if (!node->left && !node->right)
            {
                return depth;
            }
        }
    }
    return depth;
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 1;

    TreeNode *node0 = new TreeNode;
    root->val = 1;

    TreeNode *node1 = new TreeNode;
    root->val = 1;

    TreeNode *node2 = new TreeNode;
    root->val = 1;

    TreeNode *node3 = new TreeNode;
    root->val = 1;

    root->left = node0;
    root->right = node1;

    node1->left = node2;
    node1->right = node3;

    cout << minDepthLevelOrder(root) << endl;

    system("pause");
    return 0;
}
