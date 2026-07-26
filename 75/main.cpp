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
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int count0 = 0, count1 = 0, count2 = 0;

        for (int num : nums)
        {
            if (num == 0)
                count0++;
            else if (num == 1)
                count1++;
            else
                count2++;
        }

        int index = 0;

        while (count0--)
        {
            nums[index++] = 0;
        }
        while (count1--)
        {
            nums[index++] = 1;
        }
        while (count2--)
        {
            nums[index++] = 2;
        }
    }
};

int main()
{
    Solution *sol = new Solution();
}
