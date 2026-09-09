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
    int dfs(vector<vector<int>> &dp, const vector<int> &prices, int i, bool holding)
    {
        if (i == prices.size())
        {
            return 0;
        }
        if (dp[i][holding] != -1)
            return dp[i][holding];

        if (!holding)
        {
            int buy  = -prices[i] + dfs(dp, prices, i + 1, true);
            int skip = dfs(dp, prices, i + 1, false);

            return dp[i][0] = max(buy, skip);
        }
        else
        {
            int sell = prices[i] + dfs(dp, prices, i + 1, false);
            int hold = dfs(dp, prices, i + 1, true);

            return dp[i][1] = max(sell, hold);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(dp, prices, 0, false);
    }
};

int main()
{
    Solution   *sol    = new Solution();
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int         ans    = sol->maxProfit(prices);
    cout << ans << endl;
}
