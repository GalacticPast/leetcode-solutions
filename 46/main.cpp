#include "algorithm"
#include "iostream"
#include "stack"
#include "unordered_map"
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
using std::vector;

// O(n!);
class Solution
{
  public:
    void dfs(vector<int> &n, vector<vector<int>> &ans, vector<int> a, vector<int> count, int depth)
    {
        if (depth >= n.size())
        {
            ans.push_back(a);
            return;
        }
        for (int i = 0; i < n.size(); i++)
        {
            if (count[i])
            {
                a.push_back(n[i]);
                count[i]--;
                dfs(n, ans, a, count, depth + 1);
                count[i]++;
                a.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int>         count(nums.size(), 1);
        dfs(nums, ans, {}, count, 0);
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
