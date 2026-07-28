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
    void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int> &a, int ind)
    {
        if (ind >= nums.size())
        {
            if (a.size() > 0)
            {
                ans.push_back(a);
            }
            return;
        }
        dfs(ans, nums, a, ind + 1);
        a.push_back(nums[ind]);
        dfs(ans, nums, a, ind + 1);
        a.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int>         a;
        ans.push_back({});
        dfs(ans, nums, a, 0);
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
