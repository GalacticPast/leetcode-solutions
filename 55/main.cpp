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
    bool canJump(vector<int> &nums)
    {
        int          n = nums.size();
        vector<bool> link(n, 0);
        link[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n && j <= nums[i] + i; j++)
            {
                if (link[j])
                {
                    link[i] = true;
                    break;
                }
            }
        }
        return link[0];
    }
};

int main()
{
    Solution   *sol = new Solution();
    vector<int> v   = {2, 3, 1, 1, 4};
    bool        ans = sol->canJump(v);
    cout << ans << endl;
}
