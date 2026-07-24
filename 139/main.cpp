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
    bool dfs(unordered_set<string> &dict, string s, string a, int i)
    {
        if (i >= s.size())
            return false;
        a += s[i];

        bool take = dfs(dict, s, a, i + 1);
        if (dict.find(a) != dict.end())
        {
            take |= dfs(dict, s, "", i + 1);
        }
        return take;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        for (string c : wordDict)
        {
            dict.insert(c);
        }
        bool ans = dfs(dict, s, "", 0);
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
