#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string s = "We are happy.";
    string t;
    for (auto c : s)
    {
        if (c == ' ')
        {
            t += "%20";
        }
        else
        {
            t += c;
        }
        
    }

    cout << t << endl;
    

    system("pause");
    return 0;
}
