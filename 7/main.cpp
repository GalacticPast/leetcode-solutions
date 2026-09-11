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
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution
{
  public:
    int reverse(int x)
    {
        int ans = 0;

        while (x)
        {
            int pop  = x % 10;
            x       /= 10;

            if (ans > INT_MAX / 10)
                return 0;
            if (ans < INT_MIN / 10)
                return 0;
            ans = ans * 10 + pop;
        }
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
