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

void print_vec(vector<int> &a)
{
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        int         n = nums.size();
        vector<int> dp(n, 1);
        dp[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (nums[i] < nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};

int main()
{
    Solution   *sol = new Solution();
    vector<int> vec = {0, 1, 0, 3, 2, 3};
    int         ans = sol->lengthOfLIS(vec);
}
