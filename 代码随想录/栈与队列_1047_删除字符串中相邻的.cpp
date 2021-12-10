#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

string removeDuplicates(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (st.empty() || c != st.top())
        {
            st.push(c);
        }
        else
        {
            st.pop();
        }
    }

    string result = "";
    while (!st.empty())
    {
       result += st.top();
       st.pop();
    }


    reverse(result.begin(),result.end());
    
    return result;
}

int main()
{

    cout << removeDuplicates("abbaca") << endl;

    system("pause");
    return 0;
}
