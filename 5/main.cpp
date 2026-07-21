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
    bool check_palindrome(string s, int left, int right)
    {
        while (left <= right)
        {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        string ans = "";
        int    n   = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (s[i] == s[j] && check_palindrome(s, i, j))
                {
                    int len = j - i + 1;
                    if (len > ans.size())
                    {
                        ans = s.substr(i, len);
                    }
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
