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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty())
            return ans;

        int y_left   = 0;
        int y_bottom = matrix.size() - 1;
        int x_left   = 0;
        int x_right  = matrix[0].size() - 1;

        while (y_left <= y_bottom && x_left <= x_right)
        {
            for (int col = x_left; col <= x_right; col++)
            {
                ans.push_back(matrix[y_left][col]);
            }
            y_left++;

            for (int row = y_left; row <= y_bottom; row++)
            {
                ans.push_back(matrix[row][x_right]);
            }
            x_right--;

            if (y_left <= y_bottom)
            {
                for (int col = x_right; col >= x_left; col--)
                {
                    ans.push_back(matrix[y_bottom][col]);
                }
                y_bottom--;
            }

            if (x_left <= x_right)
            {
                for (int row = y_bottom; row >= y_left; row--)
                {
                    ans.push_back(matrix[row][x_left]);
                }
                x_left++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution           *sol = new Solution();
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int>         ans = sol->spiralOrder(mat);
}
