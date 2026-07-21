#include "algorithm"
#include "iostream"
#include "stack"
#include "unordered_map"
#include "utility"
#include "vector"
#include <climits>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::sort;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int ans          = 0;
        int left         = 0;
        int right        = 0;
        int sum_till_now = 0;
        for (; left < nums.size() && right < nums.size(); right++)
        {
            if (nums[left] < 0)
            {
                left++;
                continue;
            }
            sum_till_now += nums[right];
            ans           = max(sum_till_now, ans);
            while (sum_till_now < 0 && left < right)
            {
                sum_till_now -= nums[left++];
            }
        }
        if (ans == 0)
        {
            return *max_element(nums.begin(), nums.end());
        }
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
