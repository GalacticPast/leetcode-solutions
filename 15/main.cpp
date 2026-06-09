#include "algorithm"
#include "iostream"
#include "string"
#include "vector"

using std::sort;
using std::string;
using std::vector;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int left  = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left++], nums[right++]});
                    while (left < right && nums[left - 1] == nums[left])
                        left++;
                    while (left < right && nums[right - 1] == nums[right])
                        right += 2;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return ans;
    }
};
