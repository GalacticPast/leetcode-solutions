#include "stack"
#include "unordered_map"
#include "utility"
#include "vector"

using std::pair;
using std::stack;
using std::unordered_map;
using std::vector;

class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        int                   n = temp.size();
        stack<pair<int, int>> st;
        vector<int>           ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            if (!st.empty())
            {
                while (!st.empty() && st.top().first <= temp[i])
                    st.pop();

                int min = 0;
                if (!st.empty())
                {
                    min = st.top().second - i;
                }
                ans[i] = min;
            }
            st.push({temp[i], i});
        }

        return ans;
    }
};
