#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool hasPathSum(TreeNode *root, int sum)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 3;

    TreeNode *node1 = new TreeNode;
    root->val = 1;

    TreeNode *node2 = new TreeNode;
    root->val = 6;

    root->left = node1;
    root->right = node2;

    cout << hasPathSum(root, 6) << endl;

    system("pause");
    return 0;
}
