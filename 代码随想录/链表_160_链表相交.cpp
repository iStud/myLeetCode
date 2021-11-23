#include <iostream>
#include <cmath>

using namespace std;

// 走到尽头见不到你，于是走过你来时的路，等到相遇时才发现，你也走过我来时的路。

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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }
    ListNode *pA = headA, *pB = headB;
    while (pA != pB)
    {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
    }

    return pA;
}

int main()
{
    ListNode *c = new ListNode;
    c->val = 3;
    c->next = new ListNode;
    c->next->val = 4;

    

    ListNode *a = new ListNode;
    a->val = 1;

    a->next = new ListNode;
    a->next->val = 4;

    a->next->next = c;
    cout << "链表 a" << endl;
    printListNode(a);

    ListNode *b = new ListNode;
    b->val = 2;
    b->next = c;
    cout << "链表 b" << endl;
    printListNode(b);
 
    cout << "相交后" << endl;
    printListNode(getIntersectionNode(a,b));


    system("pause");
    return 0;
}
