#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 双指针，当快指针指向的值不等于val,快指针的值赋给慢指针，快慢指针都右移动。当快指针指向的值等于val，慢指针不动，快指针右移。
int removeElement(vector<int> &nums, int val)
{
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
    {
        if (nums[fastIndex] != val)
        {
            nums[slowIndex] = nums[fastIndex];
            slowIndex++;
        }
    }
    return slowIndex;
}

// 通过左右指针实现
// 左指针指向第一个元素，右指针指向最后一个元素。当左右指针相同时结束
//如果左指针指向的元素和value相等，把右指针指向的值赋给左指针指向的值，右指针左移一位。
//如果左指针指向的和value不相等，左指针左移一位
int removeEle(vector<int> &nums, int val)
{
    int left = 0;
    int right = nums.size();

    while (left < right)
    {

        if (nums[left] == val)
        {
            nums[left] = nums[right - 1];
            right--;
        }
        else
        {
            left++;
        }
    }
    return left;
}

int main()
{
    vector<int> v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(0);
    v.push_back(4);
    v.push_back(2);

    int result = removeEle(v, 2);
    cout << result << endl;

    system("pause");
    return 0;
}
