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
    int s_l(vector<int> &v, int t)
    {
        int l = 0;
        int r = v.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (v[m] >= t)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        if (l >= v.size() || l < 0 || v[l] != t)
            return -1;
        return l;
    }
    int s_r(vector<int> &v, int t)
    {
        int l = 0;
        int r = v.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (v[m] <= t)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        if (r >= v.size() || r < 0 || v[r] != t)
            return -1;
        return r;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = s_l(nums, target);
        int r = s_r(nums, target);
        return {l, r};
    }
};

int main()
{
    Solution *sol = new Solution();
}
