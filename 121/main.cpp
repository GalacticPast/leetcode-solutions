#include "algorithm"
#include "iostream"
#include "stack"
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
using std::vector;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int n          = prices.size();
        int max_profit = 0;
        int max_right  = prices[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            max_profit = max(max_right - prices[i], max_profit);
            max_right  = max(prices[i], max_right);
        }
        return max_profit;
    }
};

int main()
{
    Solution *sol = new Solution();
}
