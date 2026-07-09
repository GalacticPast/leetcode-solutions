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
    string minWindow(string s, string t)
    {
        if (t.empty() || s.empty() || s.size() < t.size())
            return "";

        vector<int> map_t(128, 0);
        vector<int> map_s(128, 0);

        int required_unique_chars = 0;
        for (char c : t)
        {
            if (map_t[c] == 0)
                required_unique_chars++;
            map_t[c]++;
        }

        int left                = 0;
        int formed_unique_chars = 0;

        int min_len   = INT_MAX;
        int start_idx = 0;

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            map_s[c]++;

            if (map_t[c] > 0 && map_s[c] == map_t[c])
            {
                formed_unique_chars++;
            }

            while (formed_unique_chars == required_unique_chars)
            {
                if (right - left + 1 < min_len)
                {
                    min_len   = right - left + 1;
                    start_idx = left;
                }

                char left_char = s[left];
                map_s[left_char]--;

                if (map_t[left_char] > 0 && map_s[left_char] < map_t[left_char])
                {
                    formed_unique_chars--;
                }
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};

int main()
{
    Solution *sol = new Solution();

    string s = "ADOBECODEBANC";
    string t = "ABC";

    string ans = sol->minWindow(s, t);
    cout << ans << endl;
}
