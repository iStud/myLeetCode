#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    v.push_back('d');
    v.push_back('e');
    v.push_back('f');
    v.push_back('g');
    v.push_back('h');
    v.push_back('i');
    v.push_back('j');

    int k = 2;
    for (int i = 0; i < v.size(); i += 2 * k)
    {
        if (i + k < v.size())
        {
            reverse(v.begin() + i, v.begin() + i + k);
            continue; // 结束本次循环，进入下次循环
        }
        reverse(v.begin() + i, v.end());
    }

    system("pause");
    return 0;
}
