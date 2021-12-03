#include <iostream>
#include <cmath>

using namespace std;

string reverseLeftWords(string s, int n)
{
    
    reverse(s.begin(), s.begin() + 2); // 先反转前两个字符串
    cout << s << endl;
    reverse(s.begin() + 2, s.end()); // 反转两个字符串后面的字符串。
    cout << s << endl;
    reverse(s.begin(), s.end()); // 反转所有字符串
    cout << s << endl;

    return s;
}

int main()
{
    string s = "abcdefg";
    cout <<  reverseLeftWords(s,2) << endl;

    system("pause");
    return 0;
}
