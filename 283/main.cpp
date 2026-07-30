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
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        // 0 1 0 3 12
        int n    = nums.size();
        int left = 0;
        while (left < n && nums[left] != 0)
        {
            left++;
        }
        int right = left;
        while (right < n && nums[right] == 0)
        {
            right++;
        }
        while (right < n && left <= right)
        {
            if (nums[right] == 0)
            {
                right++;
                continue;
            }
            swap(nums[left], nums[right]);
            left++;
            while (left < n && nums[left] != 0)
            {
                left++;
            }
            right++;
        }
    }
};

int main()
{
    Solution *sol = new Solution();
}
