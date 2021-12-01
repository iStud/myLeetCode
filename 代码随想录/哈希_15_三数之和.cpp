#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<int> >  threeSum(vector<int> &nums)
{
    int size = nums.size();
    if (size < 3)
        return {};                       // 特判
    vector<vector<int> > res;            // 保存结果（所有不重复的三元组）
    std::sort(nums.begin(), nums.end()); // 排序（默认递增）
    for (int i = 0; i < size; i++)       // 固定第一个数，转化为求两数之和
    {
        if (nums[i] > 0)
            return res; // 第一个数大于 0，后面都是递增正数，不可能相加为零了

        // 去重：如果此数已经选取过，跳过
        // if (i > 0 && nums[i] == nums[i - 1])
        //     continue;
        // 双指针在nums[i]后面的区间中寻找和为0-nums[i]的另外两个数
        int left = i + 1;
        int right = size - 1;
        while (left < right)
        {
            int value = nums[left] + nums[right] + nums[i];
            if ( value > 0)
                right--; // 两数之和太大，右指针左移
            else if (value < 0)
                left++; // 两数之和太小，左指针右移
            else
            {
                // 找到一个和为零的三元组，添加到结果中，左右指针内缩，继续寻找
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[left]);
                v.push_back(nums[right]);
                res.push_back(v);
                // res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                left++;
                right--;
                // 去重：第二个数和第三个数也不重复选取
                // while (left < right && nums[left] == nums[left - 1])
                //     left++;
                // while (left < right && nums[right] == nums[right + 1])
                //     right--;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> v;
    v.push_back(-4);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(2);



    vector<vector<int> > result = threeSum(v);
    cout << "结束" << endl;

    system("pause");
    return 0;
}
