#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int minArrLength(vector<int> &nums, int val)
{
    int length = nums.size(); // 数组的长度
    if (length == 0)
    {
        return 0;
    }

    int start = 0; // 开始点
    int end = 0; //  结束点

    int ans = INT_MAX; // 子数组的长度
    int sum = 0; // 子数组元素求和

    while (end < length) // 数组遍历一遍
    {
        sum += nums[end]; // 子数组求和

        while (sum >= val) 
        {

            sum -= nums[start]; // 缩小子数组的长度
            ans = end - start + 1; // 子数组的长度等于终点减起点加一
            start++; // 缩小子数组的长度
        }
        end++; // 右移
    }

    return ans == INT_MAX ? 0 : ans;
}

int main()
{

    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);

    int result = minArrLength(v, 6);
    cout << result << endl;

    system("pause");
    return 0;
}
