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

void print(vector<vector<int>> &grid)
{
    for (auto v : grid)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int                 m = grid.size();
        int                 n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i + 1 < m && j + 1 < n)
                {
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                }
                else if (i + 1 >= m && j + 1 < n)
                {
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                }
                else if (j + 1 >= n && i + 1 < m)
                {
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution           *sol = new Solution();
    vector<vector<int>> vec = {{1, 3, 1},
                               {1, 5, 1},
                               {4, 2, 1}};
    int                 ans = sol->minPathSum(vec);
}
