#include "algorithm"
#include "iostream"
#include "stack"
#include "unordered_map"
#include "utility"
#include "vector"

using std::cout;
using std::deque;
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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int>  dq; // Stores indices

        for (int i = 0; i < nums.size(); i++)
        {
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
            if (dq.front() < i - k + 1)
            {
                dq.pop_front();
            }

            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution   *sol = new Solution();
    vector<int> a   = {1, 3, -1, -3, 5, 3, 6, 7};
    int         k   = 3;
    vector<int> ans = sol->maxSlidingWindow(a, k);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
