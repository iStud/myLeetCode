#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        TreeNode *node = new TreeNode;
        node->val = val;
        return node;
    }

    if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }

    if (root->val < val)
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 4;

    TreeNode *node1 = new TreeNode;
    node1->val = 2;

    TreeNode *node2 = new TreeNode;
    node2->val = 7;

    root->left = node1;
    root->right = node2;

    insertIntoBST(root,5);



    system("pause");
    return 0;
}
