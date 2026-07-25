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
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        int                   max_len = 0;
        for (string c : wordDict)
        {
            int len = c.size();
            max_len = max(len, max_len);
            dict.insert(c);
        }

        int          n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && dict.find(s.substr(j, (i - j))) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution      *sol  = new Solution();
    vector<string> dict = {"aaaa", "aaa"};
    bool           ans  = sol->wordBreak("aaaaaaa", dict);
}
