#include <iostream>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

int evalRPN(vector<string> &token)
{
    stack<int> st;
    for (int i = 0; i < token.size(); i++)
    {
        // 遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。
        if (token[i] == "+" || token[i] == "-" || token[i] == "*" || token[i] == "/")
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();

            if (token[i] == "+")
            {
                st.push(num2 + num1);
            }

            if (token[i] == "-")
            {
                st.push(num2 - num1);
            }

            if (token[i] == "*")
            {
                st.push(num2 * num1);
            }

            if (token[i] == "/")
            {
                st.push(num2 / num1);
            }
        }
        else
        {
            st.push(stoi(token[i]));
        }
    }
    int result = st.top();
    st.pop();
    return result;
}

int main()
{
    vector<string> v;
    v.push_back("2");
    v.push_back("1");
    v.push_back("+");
    v.push_back("3");
    v.push_back("*");

    cout << evalRPN(v) << endl;

    system("pause");
    return 0;
}
