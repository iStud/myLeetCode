#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void reverseString(vector<char> &s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        swap(s[i], s[j]);
    }
}

int main()
{
    vector<char> c;

    c.push_back('h');
    c.push_back('e');
    c.push_back('l');
    c.push_back('l');
    c.push_back('o');

    reverseString(c);

   

    system("pause");
    return 0;
}
