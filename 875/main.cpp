#include "iostream"
#include "string"
#include "unordered_set"
#include "utility"
#include "vector"

using std::string;
using std::unordered_set;
using std::vector;

class Solution
{
  public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left  = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int ans   = INT_MAX;
        while (left <= right)
        {
            long long t = 0;
            int       k = left + (right - left) / 2;
            for (int i : piles)
            {
                t += ceil((float)i / (float)k);
                if (t > h)
                    break;
            }
            if (t <= h)
            {
                ans   = std::min(k, ans);
                right = k - 1;
            }
            else if (t > h)
            {
                left = k + 1;
            }
        }
        return ans;
    }
};
