#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int removeElement(vector<int> &v, int val)
{
    int slow = 0;
    for (int fast = 0; fast < v.size(); fast++)
    {
        if (val != v[fast])
        {
            v[slow] = v[fast];
            slow++;
        }
    }
    return slow;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    // v.push_back(3);
    // v.push_back(3);
    // v.push_back(0);
    // v.push_back(4);
    // v.push_back(2);

    cout << removeElement(v,2) << endl;

    system("pause");
    return 0;
}
