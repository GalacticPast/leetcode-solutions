#include "iostream"
#include "string"
#include "unordered_set"
#include "vector"

using std::string;
using std::unordered_set;
using std::vector;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    // row
    for (auto vec : board) {
      std::unordered_set<char> row_set;
      for (char c : vec) {
        if (c != '.') {
          if (row_set.find(c) != row_set.end()) {
            return false;
          }
          row_set.insert(c);
        }
      }
    }
    // column
    for (int i = 0; i < board.size(); i++) {
      std::unordered_set<char> column_set;
      for (int j = 0; j < board[0].size(); j++) {
        char c = board[j][i];
        if (c != '.') {
          if (column_set.find(c) != column_set.end()) {
            return false;
          }
          column_set.insert(c);
        }
      }
    }
    // box
    int x[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int y[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};

    for (int i = 1; i < board.size(); i += 3) {
      for (int j = 1; j < board[0].size(); j += 3) {
        std::unordered_set<char> box_set;
        for (int k = 0; k < 9; k++) {
          char c = board[i + y[k]][j + x[k]];
          if (c != '.') {
            if (box_set.find(c) != box_set.end()) {
              return false;
            }
            box_set.insert(c);
          }
        }
      }
    }
    return true;
  }
};
