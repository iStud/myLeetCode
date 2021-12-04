#include <iostream>
#include <cmath>

using namespace std;

int findStr(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++)
    {
        string s3 = s1.substr(i, s2.size());
        if (s3 == s2)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    string s1 = "aaa";
    string s2 = "ab";

    cout << findStr(s1, s2) << endl;

    // for (int i = 0; i < s1.size(); i++)
    // {
    //     string s3 = s1.substr(i, 2);
    //     if (s3 == s2)
    //     {
    //         cout << "相等 " << i << endl;
    //     }
    // }

    system("pause");
    return 0;
}
