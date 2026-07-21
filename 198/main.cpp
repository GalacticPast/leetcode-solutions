#include "algorithm"
#include "iostream"
#include "stack"
#include "unordered_map"
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
using std::vector;

class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> max_arr(n);

        max_arr[0] = nums[0];
        max_arr[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            max_arr[i] = max(max_arr[i - 2] + nums[i], max_arr[i - 1]);
        }
        return max(max_arr[n - 1], max_arr[n - 2]);
    }
};

int main()
{
    Solution   *sol  = new Solution();
    vector<int> nums = {114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81, 90, 222, 160, 165, 195, 187, 199, 114, 235, 197, 187, 69, 129, 64, 214, 228, 78, 188, 67, 205, 94, 205, 169, 241, 202, 144, 240};
    int         ans  = sol->rob(nums);
    cout << ans << endl;
}
