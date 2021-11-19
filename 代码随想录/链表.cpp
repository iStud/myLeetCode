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

// 链表的长度
int listNodeLength(ListNode *node)
{
    int l = 0;
    ListNode *p = node;
    while (p != NULL)
    {
        p = p->next;
        l++;
    }
    return l;
}

// 插入指定节点
ListNode *insertNode(ListNode *head, int pos, int val)
{

    ListNode *dummyNode = new ListNode;
    dummyNode->next = head;
    ListNode *p = dummyNode;
    int i = 1;
    while (p != NULL && i < pos)
    {
        p = p->next;
        i++;
    }

    ListNode *node = new ListNode;
    node->val = val;

    ListNode *tempNode = p->next;
    p->next = node;
    node->next = tempNode;

    return dummyNode->next;
}

// 删除指定节点
ListNode *deleteNode(ListNode *head, int pos)
{
    ListNode *dummyNode = new ListNode;
    dummyNode->next = head;
    ListNode *p = dummyNode;

    int i = 1;
    while (p != NULL && i < pos)
    {
        p = p->next;
        ++i;
    }

    p->next = p->next->next;

    return dummyNode->next;
}

int main()
{
    ListNode *node = create();
    printListNode(node);

    // int length = listNodeLength(node);
    // cout << "长度为 " << length << endl;

    // cout << "插入" << endl;
    // ListNode *newNode = insertNode(node, 3, 100);
    // printListNode(newNode);

    cout << "删除" << endl;
    ListNode *newNode = deleteNode(node, 4);
    printListNode(newNode);

    system("pause");
    return 0;
}
