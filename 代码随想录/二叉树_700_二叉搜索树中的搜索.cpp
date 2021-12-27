#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// 二叉搜索树，它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
// 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
// 它的左、右子树也分别为二叉排序树。

TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != NULL)
    {
        if (root->val > val)
            root = root->left;
        else if (root->val < val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 4;

    TreeNode *node1 = new TreeNode;
    node1->val = 2;

    TreeNode *node2 = new TreeNode;
    node2->val = 7;

    TreeNode *node3 = new TreeNode;
    node3->val = 1;

    TreeNode *node4 = new TreeNode;
    node4->val = 3;

    root->left = node1;
    root->right = node2;

    node1->left = node3;
    node1->right = node4;

    TreeNode *result = searchBST(root, 2);

    system("pause");
    return 0;
}
