#include <iostream>
#include <cmath>
#include <deque>
#include <vector>

using namespace std;

class Solution
{
private:
    class MyQueue
    { 
    public:
        deque<int> que;  // 用双端队列实现单调递增数列
     
        void pop(int value)
        {
            if (!que.empty() && value == que.front())
            {
                que.pop_front();
            }
        }

        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back(); // 当 push 的大于双端队列的最后一个值时就移除最后一个值
            }
            que.push_back(value);
        }
       

        int front()
        {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++)
        { 
            que.push(nums[i]);
        }
        result.push_back(que.front()); 

        // 移动滑动窗口
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]); // 移除最前面的元素
            que.push(nums[i]);             
            result.push_back(que.front()); 
        }
        return result;
    }
};

int main()
{
    Solution sl;
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(-1);
    v.push_back(3);

    vector result = sl.maxSlidingWindow(v, 3);

    system("pause");
    return 0;
}
