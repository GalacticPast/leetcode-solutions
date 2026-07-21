#include "algorithm"
#include "climits"
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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();)
        {
            int j     = i;
            int left  = intervals[i][0];
            int right = intervals[i][1];
            while (j < intervals.size()
                   && ((right >= intervals[j][0] && right <= intervals[j][1])
                       || (left >= intervals[j][0] && left <= intervals[j][1])
                       || (left >= intervals[j][0] && right <= intervals[j][1])))
            {
                left  = min(intervals[j][0], left);
                right = max(intervals[j][1], right);
                j++;
            }
            ans.push_back({left, right});
            i += j;
        }
        return ans;
    }
};

int main()
{
    Solution           *sol = new Solution();
    vector<vector<int>> vec = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = sol->merge(vec);
}
