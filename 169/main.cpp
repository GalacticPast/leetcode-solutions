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

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> map;

        for (int i : nums)
        {
            map[i]++;
        }
        int n    = nums.size();
        int half = n / 2;
        for (auto kvp : map)
        {
            if (kvp.second > half)
            {
                return kvp.first;
            }
        }
        return -1;
    }
};

int main()
{
    Solution *sol = new Solution();
}
