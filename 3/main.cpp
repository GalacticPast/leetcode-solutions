#include "algorithm"
#include "iostream"
#include "stack"
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
using std::unordered_set;
using std::vector;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;

        int n     = s.size();
        int left  = 0;
        int right = 0;

        int ans = 0;
        while (left <= right && left < n && right < n)
        {
            char r = s[right];
            while (set.find(r) != set.end())
            {
                char l = s[left];
                set.erase(l);
                left++;
            }
            ans = max(right - left + 1, ans);
            set.insert(r);
            right++;
        }
        return ans;
    }
};
int main()
{
    Solution *sol = new Solution();
}
