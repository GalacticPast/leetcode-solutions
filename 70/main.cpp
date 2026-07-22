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

class Solution
{
    vector<int> memo;

  public:
    int dfs(int n, int sum)
    {
        if (sum == n)
            return 1;
        if (sum > n)
            return 0;
        if (memo[sum] != -1)
            return memo[sum];
        int t_0   = dfs(n, sum + 1);
        int t_1   = dfs(n, sum + 2);
        memo[sum] = t_0 + t_1;
        return t_0 + t_1;
    }
    int climbStairs(int n)
    {
        memo.assign(n + 1, -1);
        int ans = dfs(n, 0);
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
    int       ans = sol->dfs(44, 0);
    cout << ans << endl;
}
