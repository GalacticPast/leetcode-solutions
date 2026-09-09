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
    int maximalSquare(vector<vector<char>> &mat)
    {
        if (mat.empty() || mat[0].empty())
            return 0;

        int m        = mat.size();
        int n        = mat[0].size();
        int max_side = 0;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mat[i - 1][j - 1] == '1')
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }

        return max_side * max_side;
    }
};

int main()
{
    Solution            *sol    = new Solution();
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    int                  ans    = sol->maximalSquare(matrix);
}
