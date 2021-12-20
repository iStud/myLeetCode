#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 如果当前节点不是叶子节点，在字符串后面拼接该节点，然后继续递归遍历该节点的左右孩子
// 如果当前节点是叶子节点，说明已经遍历完成一条路径，就加入到数组中。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

void construct_paths(TreeNode *root, string path, vector<string> &paths)
{
    if (root != NULL)
    {
        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            paths.push_back(path); 
        }
        else
        {
            path += "->";
            construct_paths(root->left, path, paths);
            construct_paths(root->right, path, paths);
        }
    }
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> paths;
    construct_paths(root, "", paths);
    return paths;
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 1;

    TreeNode *node1 = new TreeNode;
    node1->val = 2;

    TreeNode *node2 = new TreeNode;
    node2->val = 3;

    root->left = node1;
    root->right = node2;

    vector<string> result = binaryTreePaths(root);

    system("pause");
    return 0;
}
