#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

void printMap(unordered_map<int, int> &m)
{
    for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

int forNumAdd(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
{
    unordered_map<int, int> myMap;
    for (int a : A)
    {
        for (int b : B)
        {
            myMap[a + b]++; // 和为 key , 出现的次数为 value
        }
    }
    // printMap(myMap);

    int count = 0;
    for (int c : C)
    {
        for (int d : D)
        {
            
            if (myMap.find(0 - (c + d)) != myMap.end()) // 理解 0-(c+d) = (a+b) 是关键，不要被绕进去。
            {
                count += myMap[0 - (c + d)];
            }
        }
    }
    return count;
}

int main()
{

    vector<int> A;
    A.push_back(1);
    A.push_back(2);

    vector<int> B;
    B.push_back(-2);
    B.push_back(-1);

    vector<int> C;
    C.push_back(-1);
    C.push_back(2);

    vector<int> D;
    D.push_back(0);
    D.push_back(2);

    cout << "个数 " << forNumAdd(A, B, C, D) << endl;

    system("pause");
    return 0;
}
