#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};



bool isSameTree(TreeNode *p, TreeNode *q)
{

    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if (p == NULL || q == NULL)
    {
        return false;
    }
    else if (p->val != q->val)
    {
        return false;
    }
    else
    {
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
}
bool isSymmetric(TreeNode *root)
{

    if (root == NULL)
    {
        return true;
    }
    else
    {

        return isSameTree(root->left, root->right);
    }
}

int main()
{

    TreeNode *node0 = new TreeNode;
    node0->val = 1;

    TreeNode *node1 = new TreeNode;
    node1->val = 2;

    TreeNode *node2 = new TreeNode;
    node2->val = 3;

    node0->left = node1;
    node0->right = node2;

    cout << isSymmetric(node0) << endl;

    system("pause");
    return 0;
}