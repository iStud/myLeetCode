#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// 时间复杂度：O(nlogk)
// 空间复杂度：O(n)
class Solution
{
public:
    // 小顶堆
    class mycomparison
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 要统计元素出现频率, unordered_map 是无序的
        unordered_map<int, int> map; 
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        // 优先级队列，参数有 字典，数组，防函数
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 根据出现的频率构建小根堆
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        {
            cout << it->first << "--" << it->second << endl;
            pri_que.push(*it);
            if (pri_que.size() > k)
            { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(6);
    v.push_back(5);
    v.push_back(6);
    v.push_back(5);
    v.push_back(6);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(6);
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(7);

    vector<int> result = s.topKFrequent(v, 3);

    system("pause");
    return 0;
}
