#include <iostream>
#include <cmath>

using namespace std;
// 平衡二叉树
// 每个节点的左右两个子树的高度差的绝对值不超过1

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
}

int main()
{
    TreeNode *node1 = new TreeNode;
    node1->val = 3;

    TreeNode *node2 = new TreeNode;
    node2->val = 9;

    TreeNode *node3 = new TreeNode;
    node3->val = 20;

    TreeNode *node4 = new TreeNode;
    node4->val = 15;

    TreeNode *node5 = new TreeNode;
    node5->val = 7;

    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    cout << isBalanced(node1) << endl;

    system("pause");
    return 0;
}
