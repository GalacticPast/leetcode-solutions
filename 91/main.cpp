#include "algorithm"
#include "climits"
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
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution
{
  public:
    int dfs(vector<int> &dp, string s, int i)
    {
        if (i >= s.size())
        {
            return 1;
        }
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int take = dfs(dp, s, i + 1);
        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
        {
            take += dfs(dp, s, i + 2);
        }
        return dp[i] = take;
    }
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        int         ans = dfs(dp, s, 0);
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
    int       ans = sol->numDecodings("12");
    cout << ans << endl;
}
