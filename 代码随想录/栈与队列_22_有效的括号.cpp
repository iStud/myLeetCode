#include <iostream>
#include <cmath>
#include<stack>

using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
       if (s[i] == '(')
       {
           st.push(')');
       }
       else if (s[i] == '{')
       {
           st.push('}');
       }
       else if (s[i] == '[')
       {
           st.push(']');

       }
      
       else if (st.empty() || st.top() != s[i]) // (] 这种情况。
       {
           cout << st.top() << endl;
           return false;
       }
       else
       {
           st.pop();
       } 
    }

    return st.empty();
}

int main()
{
    cout << isValid("([{}])))") << endl;

    system("pause");
    return 0;
}
