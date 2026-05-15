// Example 1:
//
// Input: nums = [1,2,3,1]
//
// Output: true
//
// Explanation:
//
// The element 1 occurs at the indices 0 and 3.
//
// Example 2:
//
// Input: nums = [1,2,3,4]
//
// Output: false
//
// Explanation:
//
// All elements are distinct.
//
// Example 3:
//
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
//
// Output: true
//

#include "cstdio"
#include "unordered_map"
#include "vector"

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_map<int, int> maps;

    for (int i : nums) {
      if (maps.contains(i)) {
        return true;
      }
      maps[i]++;
    }
    return false;
  }
};

int main() {
  Solution sol;
  std::vector<int> nums = {1, 1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  bool ans = sol.containsDuplicate(nums);
  printf("%d\n", ans);
}
