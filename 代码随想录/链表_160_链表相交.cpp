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
    // 相交的部分
    ListNode *c = new ListNode;
    c->val = 3;
    c->next = new ListNode;
    c->next->val = 4;
    c->next->next = new ListNode;
    c->next->next->val = 7;

    // 链表a
    ListNode *a = new ListNode;
    a->val = 1;

    a->next = new ListNode;
    a->next->val = 4;

    a->next->next = new ListNode;
    a->next->next->val = 5;

    a->next->next->next = new ListNode;
    a->next->next->next->val = 6;

    a->next->next->next->next = c;

    cout << "链表 a" << endl;
    printListNode(a);

    // 链表 b
    ListNode *b = new ListNode;
    b->val = 2;
    b->next = c;

    cout << "链表 b" << endl;
    printListNode(b);

    cout << "相交后的链表" << endl;
    printListNode(getIntersectionNode(a, b));

    system("pause");
    return 0;
}
