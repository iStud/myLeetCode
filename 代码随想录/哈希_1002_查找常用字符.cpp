#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printString(vector<string> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

void printArr(int arr[])
{
    cout << "数组" << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << endl;
    }
}

// 字符串数组中共用字符出现的次数
vector<string> commonChars(vector<string> v)
{
     // 统计第一个字符串中字符出现的个数
    int hash[26] = {0};
    for (int i = 0; i < v[0].size(); i++)
    {
        // cout << v[0][i] << endl;
        // 获取 bella 这个字符串中的每一个字符，相同的字符减 a 获取的值是一样的，这个值是数组的下标
        // 通过下标能获取数组元素的值,累加后就能统计字符出现的次数
        hash[v[0][i] - 'a']++;
    }

    int hashOtherStr[26] = {0}; // 统计除第一个字符串外字符的出现频率
    for (int i = 1; i < v.size(); i++)
    {
        // memset 函数是内存赋值函数，用来给某一块内存空间进行赋值的；
        // 每次循环前给数组重置为 0
        memset(hashOtherStr, 0, 26 * sizeof(int));
        for (int j = 0; j < v[i].size(); j++)
        {
            hashOtherStr[v[i][j] - 'a']++;
        }

        for (int k = 0; k < 26; k++)
        {
            hash[k] = min(hash[k], hashOtherStr[k]); // 返回最小值，两次hash的比较
        }
    }

    vector<string> result;

    for (int i = 0; i < 26; i++)
    {
        int t = hash[i];
        while (t != 0)
        {

            string s(1, i + 'a'); // char 型转字符串， string 的构造函数
            result.push_back(s);
            t--;
        }
    }

    return result;
}


int main()
{

    vector<string> v;
    v.push_back("bella");
    v.push_back("label");
    v.push_back("roller");


    printString(commonChars(v));

   

    system("pause");
    return 0;
}
