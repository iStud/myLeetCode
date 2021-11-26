#include <iostream>
#include <cmath>
#include<unordered_set>

using namespace std;

bool isHappy(int n)
{
    unordered_set<int> st;
    while (n != 1)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        n = sum;
        if (st.count(n))
            break;
        st.insert(n);
    }
    return n == 1;
}

int main()
{
    bool result = isHappy(11);
    cout << result << endl;

    system("pause");
    return 0;
}
