#include <iostream>
#include <cmath>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

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

ListNode *deleteNode(ListNode *head, int val)
{
    ListNode *tempNode = new ListNode;
    tempNode->next = head;
    ListNode *p = tempNode;

    while (p->next != NULL)
    {
        
        if (p->next->val == val)
        {
           p->next = p->next->next;
        }
        else
        {
            p = p->next;
        }
        
    }
    head = tempNode->next;
    return head;
}

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

int main()
{

    ListNode *head = create();
    printListNode(head);

    cout << "删除节点" << endl;
    ListNode *newNode = deleteNode(head, 1);
    printListNode(newNode);

    system("pause");
    return 0;
}
