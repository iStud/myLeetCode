#include <iostream>
#include <cmath>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void printNode(ListNode *head)
{
    ListNode *p = head;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
}

bool hasCycly(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            cout << "有环" << endl;
            return true;
        }
    }
    cout << "无环" << endl;
    return false;
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            // 有环
            ListNode *index1 = fast;
            ListNode *index2 = slow;

            while(index1 == index2){

                index1 = index1->next;
                index2 = index1->next;

            }
            return index1;
        }
    }
    return NULL;
}

int main()
{
    /*
    
    通过快慢指针可以确认链表是否有环，遍历链表，慢指针走一步，快指针走两步，当两个指针相遇的时候说明有环。
    当获取到相遇点时，在次设置两个指针一个指向头节点一个指向相遇节点，在次遍历链表当两个指针相遇时，这个节点就是环的入口节点。

    */
    ListNode *a = new ListNode;
    a->val = 3;

    ListNode *b = new ListNode;
    b->val = 2;

    ListNode *c = new ListNode;
    c->val = 0;

    ListNode *d = new ListNode;
    d->val = -4;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = c;

    // hasCycly(a);

    ListNode *node = detectCycle(a);
    cout << "入口节点" << node->val << endl;

    system("pause");
    return 0;
}
