#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        // cout << middle << endl;

        if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else if (nums[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(12);

    int result = search(nums, 9);
    cout << result << endl;

    system("pause");
    return 0;
}
