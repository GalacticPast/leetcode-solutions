#include "iostream"
#include "stack"
#include "string"
#include "vector"

using std::stack;
using std::string;
using std::vector;

class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (string s : tokens)
        {
            if (s.length() == 1 && (s[0] == '*' || s[0] == '/' || s[0] == '+' || s[0] == '-'))
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int ans = 0;

                switch (s[0])
                {
                    case '+':
                    {
                        ans = a + b;
                    }
                    break;
                    case '*':
                    {
                        ans = a * b;
                    }
                    break;
                    case '-':
                    {
                        ans = a - b;
                    }
                    break;
                    case '/':
                    {
                        ans = a / b;
                    }
                    break;
                }
                st.push(ans);
            }
            else
            {
                int num = std::stoi(s);
                st.push(num);
            }
        }
        int ans = st.top();
        return ans;
    }
};

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    Solution *solu = new Solution();

    int ans = solu->evalRPN(tokens);
    std::cout << ans << std::endl;

    return 0;
}
