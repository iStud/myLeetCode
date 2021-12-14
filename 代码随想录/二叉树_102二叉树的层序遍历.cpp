#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// 把每一层的节点加入到队列中，控制出队入队来实现层序遍历
// 两层循环，内层循环结束前判断是否有左右子树

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
            vec.push_back(node->val);
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

int main()
{

    TreeNode *node0 = new TreeNode;
    node0->val = 3;

    TreeNode *node1 = new TreeNode;
    node1->val = 9;

    TreeNode *node2 = new TreeNode;
    node2->val = 20;

    TreeNode *node3 = new TreeNode;
    node3->val = 15;

    TreeNode *node4 = new TreeNode;
    node4->val = 7;

    node0->left = node1;
    node0->right = node2;

    node1->left = NULL;
    node1->right = NULL;

    node2->left = node3;
    node2->right = node4;

    node3->left = NULL;
    node3->right = NULL;

    node4->left = NULL;
    node4->right = NULL;

    vector<vector<int>> result = levelOrder(node0);

    system("pause");
    return 0;
}
