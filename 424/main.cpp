#include "algorithm"
#include "iostream"
#include "map"
#include "stack"
#include "utility"
#include "vector"

using std::cout;
using std::endl;
using std::map;
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
    int characterReplacement(string s, int k)
    {
        int count[26] = {0};
        int n         = s.size();

        int left       = 0;
        int max_freq   = 0;
        int max_length = 0;

        // Drive the window forward with the right pointer
        for (int right = 0; right < n; right++)
        {
            // Step 1: Unconditionally include the current character
            count[s[right] - 'A']++;

            // Step 2: Update the maximum frequency seen in any valid window state
            max_freq = max(max_freq, count[s[right] - 'A']);

            // Step 3: Check window validity.
            // Current window length minus max_freq gives the total replacements needed.
            while ((right - left + 1) - max_freq > k)
            {
                // Window is invalid; shrink from the left
                count[s[left] - 'A']--;
                left++;
            }

            // Step 4: Record the maximum valid window size found so far
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};

int main()
{
    Solution *sol = new Solution();

    string s = "AABABBA";
    int    k = 1;

    int ans = sol->characterReplacement(s, k);
    cout << ans << endl;
}
