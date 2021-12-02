#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void reverseString(vector<char> &v)
{
    for (int i = 0, j = v.size() - 1; i < v.size() / 2; i++, j--)
    {
        swap(v[i], v[j]);
    }
}

int main()
{
    vector<char> v;
    v.push_back('h');
    v.push_back('e');
    v.push_back('l');
    v.push_back('l');
    v.push_back('o');

    reverseString(v);

    system("pause");
    return 0;
}
