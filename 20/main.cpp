#include "stack"
#include "string"

using std::stack;
using std::string;

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '{' || c == '(' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (c == '}')
                {
                    if (!st.empty() && st.top() == '{')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                if (c == ')')
                {
                    if (!st.empty() && st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                if (c == ']')
                {
                    if (!st.empty() && st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};
