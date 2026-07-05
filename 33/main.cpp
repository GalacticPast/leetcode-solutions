#include "algorithm"
#include "iostream"
#include "stack"
#include "utility"
#include "vector"

using std::cout;
using std::endl;
using std::pair;
using std::sort;
using std::stack;
using std::vector;

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int n     = nums.size();
        int left  = 0;
        int right = n - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (target >= nums[left] && target < nums[mid])
            {
                right = mid - 1;
            }
            else if (target <= nums[right] && target > nums[mid])
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution *sol = new Solution();

    int         target = 0;
    vector<int> nums   = {4, 5, 6, 7, 0, 1, 2};

    int ans = sol->search(nums, target);
}
