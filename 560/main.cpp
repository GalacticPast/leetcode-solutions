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
    int subarraySum(vector<int> &nums, int k)
    {
        int n          = nums.size();
        int prefix_sum = 0;
        for (int i = 0; i < n; i++)
        {
            prefix_sum += nums[i];
        }

        int ans          = 0;
        int sum_till_now = 0;
        for (int i = 0; i < n; i++)
        {
            int tot_sum = prefix_sum - sum_till_now;
            for (int j = n - 1; j >= i; j--)
            {
                if (tot_sum == k)
                    ans++;
                tot_sum -= nums[j];
            }
            sum_till_now += nums[i];
        }
        return ans;
    }
};

int main()
{
    Solution   *sol = new Solution();
    vector<int> vec = {1, 2, 3};
    int         ans = sol->subarraySum(vec, 3);
    cout << ans << endl;
}
