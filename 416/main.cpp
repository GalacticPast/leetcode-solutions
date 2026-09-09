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
    bool dfs(vector<int> &nums, vector<vector<int>> &memo, int i, int target)
    {
        if (target == 0)
            return true;

        if (i >= nums.size() || target < 0)
        {
            return false;
        }
        if (memo[i][target] != -1)
            return memo[i][target];

        bool take       = dfs(nums, memo, i + 1, target - nums[i]);
        bool not_take   = dfs(nums, memo, i + 1, target);
        memo[i][target] = take || not_take;
        return memo[i][target];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        if (sum % 2 != 0)
            return false;

        vector<vector<int>> memo(nums.size(), vector<int>(sum / 2 + 1, -1));
        return dfs(nums, memo, 0, sum / 2);
    }
};

int main()
{
    Solution   *sol = new Solution();
    vector<int> arr = {1, 5, 11, 5};
    bool        ans = sol->canPartition(arr);
}
