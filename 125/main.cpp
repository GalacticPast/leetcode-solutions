#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
  bool isAlpha(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
  }

  bool isPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;

    while (start <= end) {
      if (isAlpha(s[start]) && isAlpha(s[end])) {
        char c_start = s[start] < 'a' ? (s[start] - 'A') + 'a' : s[start];
        char c_end = s[end] < 'a' ? (s[end] - 'A') + 'a' : s[end];
        if (c_start != c_end) {
          printf("a: %c, b: %c\n", c_start, c_end);
          return false;
        }
        start++;
        end--;
      } else if (isAlpha(s[start]) == false) {
        start++;
      } else if (isAlpha(s[end]) == false) {
        end--;
      }
    }
    return true;
  }
};
