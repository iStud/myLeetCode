#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

class MyQueue
{
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {}

    void push(int x) // 入队
    {
        stIn.push(x); // 压栈
    }

    int pop() // 出队
    {
        if (stOut.empty()) // 如果 out 栈为空则压栈否则先出栈在压栈
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }

        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek() // 队列首个元素
    {
        int res = this->pop();
        stOut.push(res);
        return res;
    }

    bool empty() // 队列是否为空
    {
        return stIn.empty() && stOut.empty();
    }
};

int main()
{

    MyQueue *queue = new MyQueue;
    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);

    int popValue = queue->pop();

    int peekValue = queue->peek();

    queue->push(5);



    system("pause");
    return 0;
}
