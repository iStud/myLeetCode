#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *mergeTreeNode(TreeNode *t1,TreeNode *t2)
{
    if(t1 == nullptr)
    {
        return t2;
    }

    if(t2 == nullptr)
    {
        return t1;
    }

    t1->val += t2->val;
    t1->left = mergeTreeNode(t1->left,t2->left);
    t2->right = mergeTreeNode(t1->right,t2->right);

    return t1;
}


int main()
{
   
   system("pause");
   return 0;
}
