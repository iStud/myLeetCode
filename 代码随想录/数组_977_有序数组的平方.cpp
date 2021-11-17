#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void MyPrint(int val)
{
    cout << val << endl;
}

vector<int> sortArr(vector<int> &nums)
{

    int k = nums.size() - 1;

    // 创建一个新的数组，存的都是0
    vector<int> results(nums.size(), 0);

    for (int i = 0, j = nums.size() - 1; i <= j;)
    {
        if (nums[i] * nums[i] < nums[j] * nums[j])
        {
            results[k] = nums[j] * nums[j];
            --j;
        }
        else
        {
            results[k] = nums[i] * nums[i]; 
            ++i;
        }
        --k;
    }
    return results;
}

int main()
{
    vector<int> v;
    v.push_back(-2);
    v.push_back(1);
    v.push_back(5);

    vector<int> results = sortArr(v);

    for_each(results.begin(), results.end(), MyPrint);

    system("pause");
    return 0;
}
