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

ListNode *reverseList(ListNode *node)
{
    ListNode *p = NULL;
    ListNode *cur = node;
    while (cur)
    {
        ListNode *temp = cur->next;
        cur->next = p;
        p = cur;
        cur = temp;
    }
    return p;
}

int main()
{
    ListNode *node = create();
    printListNode(node);

    cout << "反转" << endl;
    ListNode *newNode = reverseList(node);
    printListNode(newNode);

    system("pause");
    return 0;
}
