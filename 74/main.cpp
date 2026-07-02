#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"

using std::string;
using std::unordered_map;
using std::vector;

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            int k = matrix[i].size();
            if (target >= matrix[i][0] && target <= matrix[i][k - 1])
            {
                int left  = 0;
                int right = k - 1;
                while (left <= right)
                {
                    int mid = left + (right - left) / 2;
                    if (matrix[i][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[i][mid] < target)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};
