#include <iostream>
#include <cmath>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *create()
{
    int cycle = 1;
    int x = 1;
    ListNode *head = new ListNode;
    ListNode *p = head;

    while (cycle)
    {
        cout << "请输入链表数，输入0结束" << endl;
        cin >> x;

        if (x != 0)
        {
            ListNode *newNode = new ListNode;
            newNode->val = x;

            p->next = newNode;
            p = newNode;
        }
        else
        {
            cycle = 0;
            cout << "输入结束" << endl;
        }
    }
    p->next = NULL;
    return head->next;
}

void printNode(ListNode *node)
{
    ListNode *p = node;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
}

ListNode *swapPairs(ListNode *node)
{
    ListNode *dummyNode = new ListNode;
    dummyNode->next = node;
    ListNode *cur = dummyNode;

    while (cur->next != NULL && cur->next->next != NULL)
    {
        ListNode *oneNode = cur->next;
        ListNode *threeNode = cur->next->next->next;

        cur->next = cur->next->next;
        cur->next->next = oneNode;
        cur->next->next->next = threeNode;

        cur = cur->next->next;
    }

    return dummyNode->next;
}

int main()
{

    ListNode *node = create();
    printNode(node);

    cout << "交换" << endl;
    ListNode *newNode = swapPairs(node);
    printNode(newNode);

    system("pause");
    return 0;
}
