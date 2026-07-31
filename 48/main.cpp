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
    void mat_multiply(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> rev_iden(m, vector<int>(n, 0));
        vector<vector<int>> iden(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            rev_iden[i][n - i - 1] = 1;
            iden[i][i]             = 1;
        }
        for (int i = 0; i < m; i++)
        {
            int ind = 0;
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = matrix[i][j] * rev_iden[ind][n - 1 - ind];
                ind++;
            }
        }
        for (int i = 0; i < m; i++)
        {
            int ind = 0;
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = matrix[i][j] * iden[ind][ind];
                ind++;
            }
        }
    }
    void rotate(vector<vector<int>> &matrix)
    {
        mat_multiply(matrix);
    }
};

int main()
{
    Solution *sol = new Solution();
}
