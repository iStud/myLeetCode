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

TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
{
    if (postorder.size() == 0)
    {
        return NULL;
    }

    int value = postorder[postorder.size() - 1];
    TreeNode *root = new TreeNode;
    root->val = value;

    // 只有一个节点
    if (postorder.size() == 1)
    {
        return root;
    }

    // 分割中序数组和后序数组
    int index;
    for (index = 0; index < inorder.size(); index++)
    {
        if (inorder[index] == value)
            break;
    }

    // 分割左数组

    vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
    vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

    // 分割右数组
    // 去除最后一个元素
    postorder.resize(postorder.size() - 1);
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
    vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

    root->left = traversal(leftInorder, leftPostorder);
    root->right = traversal(rightInorder, rightPostorder);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{

    if (inorder.size() == 0 || postorder.size() == 0)
        return NULL;
    return traversal(inorder, postorder);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};   // 中序
    vector<int> postorder = {9, 15, 7, 20, 3}; // 后序

    buildTree(inorder, postorder);

    system("pause");
    return 0;
}
