#include <iostream>
#include <cmath>

using namespace std;

void reverse(string &s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
}

void removeExtraSpaces(string &s) // 本题关键
{
    int a = s.size();
    int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
    // 去掉字符串前面的空格
    while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ')
    {
        fastIndex++;
    }
    for (; fastIndex < s.size(); fastIndex++) // 通过移动字符的位置消除空格
    {
        // 去掉字符串中间部分的冗余空格
        if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ')
        {
            continue;
        }
        else
        {
            s[slowIndex++] = s[fastIndex]; // slowindex 先赋值后自增
        }
    }
    if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ')
    {                            // 去掉字符串末尾的空格
        s.resize(slowIndex - 1); //字符串的大小调整为 slowindex - 1 个字符
    }
    else
    {
        s.resize(slowIndex); // 重新设置字符串大小
    }
}

int main()
{
    string s = "  he  wo ";

    // 这题的关键是去除多余的空格
    removeExtraSpaces(s);

    cout << s << endl;

    reverse(s.begin(), s.end());
    // reverse(s, 0, s.size() - 1); // 先对字符串进行反转

    for (int i = 0; i < s.size(); i++)
    {
        int j = i;

        while (j < s.size() && s[j] != ' ')
            j++;

        reverse(s.begin() + i, s.begin() + j);
        // reverse(s, i, j - 1);

        i = j;
    }
    // cout << s << endl;

    system("pause");
    return 0;
}
