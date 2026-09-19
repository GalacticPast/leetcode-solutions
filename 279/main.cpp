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
    int dfs(int target, vector<int> &memo)
    {
        if (target == 0)
            return 0;
        if (memo[target] != -1)
            return memo[target];

        int min_count = INT_MAX;
        for (int j = 1; j * j <= target; j++)
        {
            min_count = min(min_count, 1 + dfs(target - j * j, memo));
        }

        return memo[target] = min_count;
    }

    int numSquares(int n)
    {
        vector<int> memo(n + 1, -1);
        return dfs(n, memo);
    }
};

int main()
{
    Solution *sol = new Solution();
    int       ans = sol->numSquares(1234);
}
