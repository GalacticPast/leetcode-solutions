#include "algorithm"
#include "iostream"
#include "stack"
#include "unordered_map"
#include "unordered_set"
#include "utility"
#include "vector"

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::sort;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution
{
  public:
    void dfs(vector<string> &ans,
             vector<string> &letters,
             string         &digits,
             string         &s,
             int             ind)
    {
        if (ind >= digits.size())
        {
            ans.push_back(s);
            return;
        }
        int    c    = digits[ind] - '0';
        string word = letters[c];
        for (char a : word)
        {
            s.push_back(a);
            dfs(ans, letters, digits, s, ind + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string         s;
        dfs(ans, letters, digits, s, 0);
        return ans;
    }
};
int main()
{
    Solution *sol = new Solution();
}
