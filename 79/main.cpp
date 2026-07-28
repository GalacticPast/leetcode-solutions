#include "algorithm"
#include "iostream"
#include "stack"
#include "unordered_map"
#include "unordered_set"
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
using std::unordered_set;
using std::vector;

class Solution
{
    bool found = false;

  public:
    bool dfs(vector<vector<char>> &board, vector<vector<int>> &visited, string &word, string &a, int y, int x, int ind)
    {
        if (found || word == a)
        {
            found = true;
            return true;
        }
        if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size() || ind >= word.size())
            return false;
        if (visited[y][x])
            return false;
        visited[y][x] = true;
        if (board[y][x] == word[ind])
        {
            a += word[ind];
            dfs(board, visited, word, a, y - 1, x, ind + 1);
            dfs(board, visited, word, a, y + 1, x, ind + 1);
            dfs(board, visited, word, a, y, x - 1, ind + 1);
            dfs(board, visited, word, a, y, x + 1, ind + 1);
            a.pop_back();
        }
        visited[y][x] = false;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (word[0] == board[i][j])
                {
                    string a = "";
                    dfs(board, visited, word, a, i, j, 0);
                }
            }
        }
        return found;
    }
};

int main()
{
    Solution *sol = new Solution();
}
