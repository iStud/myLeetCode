#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

void printMap(unordered_map<int, int> &m)
{
    for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

vector<int> twoSum(vector<int> &nums, int target)
{
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        // 先在 map 中查询是否有这个值，如果没有就插入，有就返回。
        auto iter = map.find(target - nums[i]); // 返回的是一个迭代器，find 查的是 key

        if (iter != map.end())
        {
            cout << "找到了 " << endl;
            return {iter->second, i}; // iter->second 是 map 中 key 的值。
        }
        else
        {
            cout << "未找到元素" << endl;
            map.insert(pair<int, int>(nums[i], i));
            printMap(map);
        }
    }
    
    return {};
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);

    int target = 18;

    vector<int> result = twoSum(v, target);
    printVector(result);

    system("pause");
    return 0;
}
