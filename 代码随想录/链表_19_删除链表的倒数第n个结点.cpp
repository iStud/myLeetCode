#include <iostream>
#include <cmath>

using namespace std;

// 单链表数据结构
struct ListNode
{
    int val;
    ListNode *next;
};

// 创建一个链表
ListNode *create()
{
    ListNode *head = new ListNode; // 创建了一个头节点
    ListNode *p = head;            // p 指针指向了这个节点

    int x, cycle = 1;
    while (cycle)
    {
        cout << "请输入链表数据,输入0结束输入" << endl;
        cin >> x;

        if (x != 0)
        {

            ListNode *node = new ListNode; // 循环创建新的节点并给新的节点赋值
            node->val = x;

            p->next = node;
            p = node;
        }
        else
        {
            cycle = 0;
            cout << "输入完成" << endl;
        }
    }

    head = head->next;
    p->next = NULL;

    return head;
}

// 打印链表
void printListNode(ListNode *node)
{
    ListNode *p = node; // p 指向链表第一个节点
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
}

ListNode *deleateIndex(ListNode *node, int n)
{
    ListNode *dummyNode = new ListNode;
    dummyNode->next = node;
    ListNode *fast = node;      // 快指针指向第一个节点，
    ListNode *slow = dummyNode; // 慢指针指向虚拟节点

    for (int i = 0; i < n; i++) // 快指针先走n步
    {
        fast = fast->next;
    }

    while (fast) // 当 fast 指向空的时候，slow 指向删除节点的前一个节点。
    {
        fast = fast->next; // 当走第2步的时候，fast 依旧不为空
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummyNode->next;
}

int main()
{

    ListNode *node = create();
    printListNode(node);

    cout << "删除倒数第二个节点" << endl;
    ListNode *newNode = deleateIndex(node, 2);
    printListNode(newNode);

    system("pause");
    return 0;
}
