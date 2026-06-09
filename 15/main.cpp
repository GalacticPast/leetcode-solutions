#include "iostream"
#include "string"
#include "vector"

using std::string;
using std::vector;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<bool> used(nums.size());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        for (int k = j + 1; k < nums.size(); k++) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            if (!used[i] || !used[j] || !used[k]) {
              ans.push_back({nums[i], nums[j], nums[k]});
              used[i] = true;
              used[j] = true;
              used[k] = true;
            }
          }
        }
      }
    }
    return ans;
  }
};
