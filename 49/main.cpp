#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    int length = strs.size();
    unordered_map<string, vector<string>> map;

    for (int i = 0; i < length; i++) {
      int sum = 0;
      string s = strs[i];
      sort(s.begin(), s.end());
      auto ptr = map.find(s);
      if (ptr == map.end()) {
        map[s] = {strs[i]};
      } else {
        ptr->second.push_back(strs[i]);
      }
    }
    vector<vector<string>> ans;

    for (auto ptr : map) {
      ans.push_back(ptr.second);
    }

    return ans;
  }
};
