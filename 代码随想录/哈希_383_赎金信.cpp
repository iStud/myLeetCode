#include <iostream>
#include <cmath>

using namespace std;

bool canConstruct(string stringA, string stringB)
{
    int record[26] = {0};
    for (int i = 0; i < stringB.length(); i++)
    {
        record[stringB[i] - 'a']++;
    }

    for (int j = 0; j < stringA.length(); j++)
    {
        record[stringA[j] - 'a']--;
        if (record[stringA[j] - 'a'] < 0) // 说明在 stringA 中的字符在 stringB 中没有出现过
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string stringA = "aa";
    string stringB = "aabb";

    cout << canConstruct(stringA,stringB) << endl;

    system("pause");
    return 0;
}
