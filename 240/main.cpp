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
    bool binary_search(vector<vector<int>> &matrix, int target, int y, int x)
    {
        // horizontal
        int left  = x;
        int right = matrix[y].size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid >= 0 && mid <= right && matrix[y][mid] == target)
                return true;
            else if (matrix[y][mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        // vertical
        left  = y;
        right = matrix.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid >= 0 && mid <= right && matrix[mid][x] == target)
                return true;
            else if (matrix[mid][x] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (binary_search(matrix, target, i, i))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution *sol = new Solution();
}
