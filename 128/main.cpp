#include "iostream"
#include "string"
#include "unordered_set"
#include "vector"

using std::string;
using std::unordered_set;
using std::vector;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set;
    for (int i : nums) {
      set.insert(i);
    }
    int ans = 0;
    for (auto val : set) {
      if (set.find(val - 1) != set.end()) {
        continue;
      }
      int temp = val;
      int max = 0;
      for (;;) {
        if (set.find(temp++) == set.end())
          break;
        max += 1;
      }
      ans = max > ans ? max : ans;
    }
    return ans;
  }
};
