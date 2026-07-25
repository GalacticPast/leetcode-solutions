#include "algorithm"
#include "iostream"
#include "set"
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
    void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int> &a, int target, int start)
    {
        if (target == 0)
        {
            ans.push_back(a);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            if (nums[i] > target)
                continue;
            int t = target - nums[i];
            a.push_back(nums[i]);
            dfs(ans, nums, a, t, i);
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> a;
        dfs(ans, candidates, a, target, 0);

        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
