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
using std::unordered_map;
using std::unordered_set;
using std::vector;

// 2 3 1 1 4

class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int         n = nums.size();
        vector<int> arr(n, 10001);

        for (int i = n - 2; i >= 0; i--)
        {
            if (i + nums[i] >= n - 1)
            {
                arr[i] = 1;
            }
            else
            {
                int a = nums[i];
                for (int j = i + 1; j < n && a; j++, a--)
                {
                    arr[i] = min(arr[i], 1 + arr[j]);
                }
            }
        }
        return arr[0];
    }
};

int main()
{
    Solution   *sol = new Solution();
    vector<int> arr = {2, 3, 1, 1, 4};
    int         ans = sol->jump(arr);
    cout << ans << endl;
}
