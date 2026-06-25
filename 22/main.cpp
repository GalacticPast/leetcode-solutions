#include "string"
#include "vector"

using std::string;
using std::vector;

class Solution
{
  public:
    void backtrack(vector<string> &ans, string current_string, int open, int close, int n)
    {
        if (current_string.length() == 2 * n)
        {
            ans.push_back(current_string);
            return;
        }

        if (open < n)
        {
            backtrack(ans, current_string + "(", open + 1, close, n);
        }
        if (close < open)
        {
            backtrack(ans, current_string + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
};
