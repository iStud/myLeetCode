#include <iostream>
#include <cmath>
#include<queue>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    // TreeNode(int x):value(x),left(NULL),right(NULL){}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    // 定义一个队列
    queue<TreeNode *> que;
    vector<vector<int>> result;

    if (root != NULL)
    {
        que.push(root);
    }
    while (!que.empty())
    {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            vec.push_back(node->value);
            que.pop();

            // 当上层节点弹出后，判断是否有左右子树，有就加入队列中
            if (node->left)
            {
                que.push(node->left);
            }

            if (node->right)
            {
                que.push(node->right);
            }
        }
        result.push_back(vec);
    }
    return result;
}



// 把每个节点的左右孩子交换一下即可
TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
    {
        return root;
    }
    
    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main()
{
    TreeNode *node0 = new TreeNode;
    node0->value = 4;

    TreeNode *node1 = new TreeNode;
    node1->value = 2;

    TreeNode *node2 = new TreeNode;
    node2->value = 7;

    TreeNode *node3 = new TreeNode;
    node3->value = 1;

    TreeNode *node4 = new TreeNode;
    node4->value = 3;

    TreeNode *node5 = new TreeNode;
    node5->value = 6;

    TreeNode *node6 = new TreeNode;
    node6->value = 9;

    node0->left = node1;
    node0->right = node2;

    node1->left = node3;
    node1->right = node4;

    node2->left = node5;
    node2->right = node6;

    node3->left = NULL;
    node3->right = NULL;

    node4->left = NULL;
    node4->right = NULL;

    node5->left = NULL;
    node5->right = NULL;

    node5->left = NULL;
    node5->right = NULL;

    TreeNode *result = invertTree(node0);

    vector<vector<int>> newRoot = levelOrder(result);

    system("pause");
    return 0;
}
