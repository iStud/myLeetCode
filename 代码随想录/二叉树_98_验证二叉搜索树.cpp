#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<int> vec;

// 二叉搜索树的中序遍历是一个有序数组
void traversal(TreeNode *root)
{
    if (root == NULL)
        return;
    traversal(root->left);
    vec.push_back(root->val); // 将二叉搜索树转换为有序数组
    traversal(root->right);
}

bool isValidBST(TreeNode *root)
{
    vec.clear();
    traversal(root);
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < vec[i - 1])
            return false;
    }
    return true;
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 2;

    TreeNode *node1 = new TreeNode;
    node1->val = 1;

    TreeNode *node2 = new TreeNode;
    node2->val = 3;

    root->left = node1;
    root->right = node2;

    cout << isValidBST(root) << endl;

    system("pause");
    return 0;
}
