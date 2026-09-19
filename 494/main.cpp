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
    int dfs(vector<vector<int>> &dp, vector<int> &nums, int i, int sum, int target, int pivot)
    {
        if (i >= nums.size())
        {
            if (sum == target)
                return 1;
            return 0;
        }
        if (dp[i][sum + pivot] != -1)
            return dp[i][sum + pivot];
        int plus                  = dfs(dp, nums, i + 1, sum + nums[i], target, pivot);
        int minus                 = dfs(dp, nums, i + 1, sum - nums[i], target, pivot);
        return dp[i][sum + pivot] = plus + minus;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(sum + sum + 1, -1));
        return dfs(dp, nums, 0, 0, target, sum);
    }
};

int main()
{
    Solution *sol = new Solution();
}
