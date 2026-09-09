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
    string longestCommonPrefix(vector<string> &strs)
    {
        unordered_map<string, int> map;

        for (string s : strs)
        {
            for (int i = 1; i <= s.size(); i++)
            {
                string pre = s.substr(0, i);
                if (map.find(pre) != map.end())
                {
                    map[pre]++;
                }
                else
                {
                    map[pre] = 1;
                }
            }
        }
        string ans = "";
        for (auto kvp : map)
        {
            if (kvp.second == strs.size())
            {
                if (ans.size() < kvp.first.size())
                {
                    ans = kvp.first;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
