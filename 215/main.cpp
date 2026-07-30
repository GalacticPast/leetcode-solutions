#include "algorithm"
#include "iostream"
#include "queue"
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
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> set;
        for (int i : nums)
        {
            set.push(i);
        }
        while (--k)
        {
            set.pop();
        }
        return set.top();
    }
};

int main()
{
    Solution *sol = new Solution();
}
