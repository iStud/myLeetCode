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
void traversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    traversal(root->left);
    vec.push_back(root->val);
    traversal(root->right);
}

int minValue(TreeNode *root)
{
    vec.clear();
    traversal(root);

    if (vec.size() < 2)
        return 0;

    int result = INT_MAX;
    for (int i = 1; i < vec.size(); i++)
    {
        result = min(result, vec[i] - vec[i - 1]);
    }

    return result;
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 2;

    TreeNode *node1 = new TreeNode;
    node1->val = 1;

    TreeNode *node2 = new TreeNode;
    node2->val = 8;

    root->left = node1;
    root->right = node2;

    cout << minValue(root) << endl;

    system("pause");
    return 0;
}
