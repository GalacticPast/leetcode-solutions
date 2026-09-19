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
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution
{
  public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int count[27]          = {0};
        int remaining_time[26] = {INT_MAX};
        count[26]              = INT_MAX;
        for (char c : tasks)
        {
            count[c - 'A']++;
            remaining_time[c - 'A'] = 0;
        }
        int ans = 0;
        while (true)
        {
            int min_ind  = 27;
            int min_time = INT_MAX;
            for (int i = 0; i < 26; i++)
            {
                if (count[i] > 0 && count[i] >= count[min_ind] && remaining_time[i] < min_time)
                {
                    min_ind  = i;
                    min_time = remaining_time[i];
                }
            }
            if (min_ind == 27 && min_time == INT_MAX)
                break;

            int minus = min_time == 0 ? 1 : min_time;
            for (int i = 0; i < 26; i++)
            {
                if (remaining_time[i] != 0)
                {
                    remaining_time[i] -= min_time;
                }
            }
            remaining_time[min_ind] = n;
            count[min_ind]--;
            if (min_time > 0)
            {
                ans += min_time;
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution    *sol = new Solution();
    vector<char> vec = {'A', 'A', 'A', 'B', 'B', 'B'};
    int          ans = sol->leastInterval(vec, 2);
    cout << ans << endl;
}
