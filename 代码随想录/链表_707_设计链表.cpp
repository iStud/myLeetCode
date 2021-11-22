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

    ListNode *head = new ListNode;
    ListNode *p = head;

    int x = 1;

    int cycle = 1;
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

    p->next = NULL;

    return head->next;
}

void printNode(ListNode *node)
{
    ListNode *head = node;
    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

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

int getNodeValue(int index, ListNode *node)
{
    int l = listNodeLength(node);
    if (index < 0 || index > l)
    {
        return -1;
    }

    ListNode *dummyNode = new ListNode;
    dummyNode->next = node;
    ListNode *p = dummyNode;
    int i = 0;

    while (p != NULL && i < index)
    {
        p = p->next;
        ++i;
    }

    return p->val;
}

ListNode *addAtHead(ListNode *node, int val)
{
    ListNode *dummyNode = new ListNode;
    dummyNode->next = node;
    ListNode *p = dummyNode;

    ListNode *newNode = new ListNode;
    newNode->val = val;

    ListNode *tempNode = p->next;
    p->next = newNode;
    newNode->next = tempNode;

    return dummyNode->next;
}

ListNode *addAtTail(int val, ListNode *node)
{
    ListNode *dummyNode = new ListNode;
    dummyNode->next = node;
    ListNode *p = dummyNode;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ListNode *newNode = new ListNode;
    newNode->val = val;

    p->next = newNode;
    p = newNode;
    p->next = NULL;

    return dummyNode->next;
}

ListNode *insertAtIndex(ListNode *node, int index, int val)
{
    ListNode *dummyNode = new ListNode;
    dummyNode->next = node;
    ListNode *p = dummyNode;
    int i = 1;
    while (p->next != NULL && i < index)
    {
        p = p->next;
        ++i;
    }

    ListNode *newNode = new ListNode;
    newNode->val = val;

    ListNode *tempNode = p->next;
    p->next = newNode;
    newNode->next = tempNode;

    return dummyNode->next;
}

ListNode *deleteAtIndex(int index, ListNode *node)
{
    ListNode *dummyNode = new ListNode;
    ListNode *p = dummyNode;
    dummyNode->next = node;
    int i = 1;

    while (p->next != NULL && i < index)
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
    cout << "打印输出" << endl;
    printNode(node);

    // cout << "index" << endl;
    // int val = getNodeValue(2, node);
    // cout << val << endl;

    // cout << "头插入" << endl;
    // ListNode *newNode = addAtHead(node, 12);
    // printNode(newNode);

    // cout << "尾插入" << endl;
    // ListNode *newNode = addAtTail(12, node);
    // printNode(newNode);

    // cout << "插入" << endl;
    // ListNode *newNode = insertAtIndex(node, 1, 100);
    // printNode(newNode);

    cout << "删除" << endl;
    ListNode *newNode = deleteAtIndex(5, node);
    printNode(newNode);

    system("pause");
    return 0;
}
