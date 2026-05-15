#include "string"
#include "unordered_map"

using std::string;
using std::unordered_map;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;
    bool res = false;

    unordered_map<char, int> map;
    for (char c : s) {
      map[c]++;
    }
    for (char c : t) {
      if (map.contains(c)) {
        map[c]--;
        if (map[c] == 0) {
          map.erase(c);
        }
      }
    }
    return map.size() == 0 ? true : false;
  }
};

int main() {
  Solution sol;
  bool res = sol.isAnagram("racecar", "racecar");
  printf("%d\n", res);
}
