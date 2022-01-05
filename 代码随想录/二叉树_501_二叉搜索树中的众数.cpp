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

int cot;
int maxCount;
int base;
vector<int> result;

void updateValue(int value)
{

    if (base == value)
    {
        cot++;
    }
    else
    {
        base = value;
        cot = 1;
    }

    if (cot == maxCount)
    {
        result.push_back(base);
    }

    if (cot > maxCount)
    {
        maxCount = cot;
        result = vector<int>{base};
    }
}

void searchBST(TreeNode *root)
{
    if (root == nullptr)
        return;

    searchBST(root->left);
    updateValue(root->val);
    searchBST(root->right);
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 1;

    TreeNode *node1 = new TreeNode;
    node1->val = 2;

    TreeNode *node2 = new TreeNode;
    node2->val = 2;

    root->right = node1;
    node1->right = node2;

    searchBST(root);

    cout << result << endl;


    system("pause");
    return 0;
}
