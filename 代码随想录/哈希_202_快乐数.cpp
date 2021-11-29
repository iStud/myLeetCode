#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

/*

19 是不是快乐数

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

bool isHappy(int n)
{
    unordered_set<int> st; // 快速判断一个元素是否出现集合里
    while (n != 1)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10); 
            n /= 10;
            // 比如19这个数,
            // 第一次循环的时候 sum = (19 % 10) * (19 % 10) = 9 * 9 = 9^2，n = 19/10 = 1.
            // 第二次循环的时候 sum = 9^2 + (1%10) * (1%10) = 9^2 + 1^2 ,n = 1 / 10 = 0.
            // 循环结束
        }
        n = sum;
        if (st.count(n)) // 判断这个数曾经是不是计算过。
            break; // 完全结束循环
        st.insert(n);
    }
    return n == 1;
}


/*



11 是不是快乐数？

1^2 + 1^2 = 2
2^2 = 4
4^2 = 16
1^2 + 6^2 = 37
3^2 + 7^2 = 58
5^2 + 8^2 = 89
8^2 + 9^2 = 145
1^2 + 4^2 + 5^2 = 42
4^2 + 2^2 = 20
2^2 + 0^2 = 4

最后一次计算的时候发现 4 已经在集合中了就立刻结束循环，不是快乐数


*/


int main()
{
    bool result = isHappy(11);
    cout << result << endl;

    system("pause");
    return 0;
}
