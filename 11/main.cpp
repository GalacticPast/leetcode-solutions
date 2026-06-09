#include "algorithm"
#include "iostream"
#include "string"
#include "vector"
#include <algorithm>

using std::max;
using std::min;
using std::sort;
using std::string;
using std::vector;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int n        = height.size();

        int left  = 0;
        int right = n - 1;

        while (left < right)
        {
            int min_height = min(height[left], height[right]);
            int length     = right - left;
            max_area       = max(min_height * length, max_area);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max_area;
    }
};
