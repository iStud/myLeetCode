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

// 数组中的最大值是左右子树的分界线，左数组中的最大值又是各自左右子树分界线，右子树也是一样。

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{

    TreeNode *root = new TreeNode;
    if (nums.size() == 1)
    {
        root->val = nums[0];
        // return root;
    }

    // 求数组中的最大值
    int maxIndex = 0;
    int maxValue = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxValue)
        {
            maxValue = nums[i];
            maxIndex = i;
        }
    }

    root->val = maxValue;

    // 左子树数组
    if (maxIndex > 0)
    {
        vector<int> newV(nums.begin(), nums.begin() + maxIndex);
        root->left = constructMaximumBinaryTree(newV);
    }

    // 右子树数组
    if (maxIndex < nums.size() - 1)
    {
        vector<int> newV(nums.begin() + maxIndex + 1, nums.end());
        root->right = constructMaximumBinaryTree(newV);
    }

    return root;
}

int main()
{
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode *result = constructMaximumBinaryTree(nums);

    system("pause");
    return 0;
}
