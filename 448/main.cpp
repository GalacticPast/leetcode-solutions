#include "algorithm"
#include "climits"
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
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            int t        = nums[i] & ((1 << 18) - 1);
            nums[t - 1] |= (1 << 18);
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & (1 << 18))
                continue;
            ans.push_back(i + 1);
        }

        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
