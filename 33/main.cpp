#include "algorithm"
#include "iostream"
#include "stack"
#include "utility"
#include "vector"

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::sort;
using std::stack;
using std::vector;

class Solution
{
  public:
    int bin_search(vector<int> &nums, int target, int left, int right)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return -1;

        int left  = 0;
        int right = n - 1;

        // Pass 1: Find the absolute MAXIMUM element index
        while (left < right)
        {
            // Note the +1 to force rounding up, preventing infinite loops
            int mid = left + (right - left + 1) / 2;

            if (nums[mid] >= nums[left])
            {
                left = mid; // Max is at mid or to the right
            }
            else
            {
                right = mid - 1; // Max is strictly to the left
            }
        }

        int max_p = left; // left and right converged on the maximum element

        // Pass 2: The inflection point is the index right after the max element
        int inf_p = (max_p + 1) % n;

        // Pass 3: Standard Binary Search on the correct partition
        if (target >= nums[inf_p] && target <= nums[n - 1])
        {
            return bin_search(nums, target, inf_p, n - 1);
        }
        else
        {
            return bin_search(nums, target, 0, max_p);
        }
    };
};

int main()
{
    Solution *sol = new Solution();

    int         target = 3;
    vector<int> nums   = {1};

    int ans = sol->search(nums, target);
}
