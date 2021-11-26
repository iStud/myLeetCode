#include <iostream>
#include <cmath>

using namespace std;

// 字母异位：两字符串中，字符的出现的个数相同。
bool isAnagram(string s, string t)
{
    int record[26] = {0}; // 创建一个长度为26的数组，因为 a-z 共有26个。
    for (int i = 0; i < s.size(); i++)
    {
        // s[i] 的意思：返回 s 中位置为 i 的字符
        record[s[i] - 'a']++; // 如果是相同元素那么它减去 a 后获取的下标值是相同的，然后取出元素做累加。
    }

    for (int i = 0; i < t.size(); i++)
    {
        record[t[i] - 'a']--; // 和上面的累加相反做减法，如果都为 0 则说明字符出现的次数是相同的。
    }

    for (int i = 0; i < 26; i++)
    {
        if (record[i] != 0) // 如果所有元素都为 0 则是字母异位
        {

            return false;
        }
    }

    return true;
}

int main()
{
    bool result = isAnagram("agram", "nagaram");
    cout << result << endl;

    system("pause");
    return 0;
}
