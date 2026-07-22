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
    int maxProduct(vector<int> &nums)
    {
        int m_a = INT_MIN;
        int n   = nums.size();
        for (int i = 0; i < n; i++)
        {
            int m            = nums[i];
            int max_till_now = m;
            for (int j = i + 1; j < n; j++)
            {
                m            *= nums[j];
                max_till_now  = max(m, max_till_now);
            }
            m_a = max(max_till_now, m_a);
        }
        return m_a;
    }
};

int main()
{
    Solution *sol = new Solution();
}
