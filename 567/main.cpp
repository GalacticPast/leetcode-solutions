#include "algorithm"
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
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();
        if (m > n)
            return false;

        vector<int> s1_c(26);
        vector<int> s2_c(26);

        for (int i = 0; i < m; i++)
        {
            s1_c[s1[i] - 'a']++;
            s2_c[s2[i] - 'a']++;
        }
        if (s1_c == s2_c)
            return true;

        for (int i = m; i < n; i++)
        {
            s2_c[s2[i] - 'a']++;
            s2_c[s2[i - m] - 'a']--;
            if (s1_c == s2_c)
                return true;
        }
        return false;
    }
};
int main()
{
    Solution *sol = new Solution();
}
