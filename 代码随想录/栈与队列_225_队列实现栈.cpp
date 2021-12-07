#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> que;

    MyStack() {}

    void push(int x) // 压栈
    {
        que.push(x); // 入队
    }

    int pop() // 出栈
    {
        int size = que.size();
        size--;
        while (size--) // 除队列尾部外，把队列的头部插入到队列的尾部
        {
            que.push(que.front());
            que.pop();
        }

        int result = que.front();
        que.pop();
        return result;
    }

    int top()
    {
        return que.back();
    }

    bool empty()
    {
        return que.empty();
    }
};

int main()
{
    MyStack *queue = new MyStack;
    queue->push(1);
    queue->push(2);
    queue->push(3);

    queue->pop();

    queue->push(7);
    queue->push(8);
    queue->push(9);

    system("pause");
    return 0;
}
