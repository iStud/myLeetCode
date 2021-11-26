#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

// 打印 set 
void printSet(unordered_set<int> &s)
{
    for (unordered_set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 打印数组
void printVector(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}

// 两个数组的交集
vector<int> intersection(vector<int> &v1, vector<int> &v2)
{
    unordered_set<int> result_set;
    unordered_set<int> v1_set(v1.begin(), v1.end());
    // printSet(v1_set);

    for (int num : v2) // c++ 11,for循环
    {
        if (v1_set.find(num) != v1_set.end()) // 数组v2中的值在v1中是否出现过。
        {
            result_set.insert(num);
        }
    }
    return vector<int>(result_set.begin(), result_set.end());
}

int main()
{

    // 两个数组的交集
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(1);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(2);

    printVector(intersection(v1,v2));

    system("pause");
    return 0;
}
