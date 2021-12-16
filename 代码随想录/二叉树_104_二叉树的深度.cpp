#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int getDepth(TreeNode *root) // 后续遍历的一种写法
{
    if (root == NULL)
    {
        return 0;
    }
    int leftDepth = getDepth(root->left);
    int rightDethp = getDepth(root->right);
    int maxDepth = 1 + max(leftDepth, rightDethp); // 根节点的高度就是二叉树的最大深度
    return maxDepth;
}

// 前序遍历的写法
int result; // 深度
void getDepthVLR(TreeNode *root, int depth)
{
    // 当节点数大于1时，深度的判断
    result = depth > result ? depth : result; // 中间节点
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root->left)
    {
        getDepthVLR(root->left, depth + 1);
    }

    if (root->right)
    {
        getDepthVLR(root->right, depth + 1);
    }
    return;
}

int maxDepth(TreeNode *root)
{
    result = 0;
    if (root == NULL) // 没有节点
    {
        return result;
    }

    getDepthVLR(root, 1); // 节点数大于1

    return result;
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

    cout << maxDepth(root) << endl;

    system("pause");
    return 0;
}
