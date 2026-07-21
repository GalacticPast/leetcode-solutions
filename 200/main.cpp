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
    void flood_fill(vector<vector<char>> &grid, int y, int x, char c)
    {
        if (y < 0 || x < 0 || y >= grid.size() || x >= grid[0].size() || grid[y][x] != '1')
            return;

        grid[y][x] = c;

        flood_fill(grid, y - 1, x, c); // up
        flood_fill(grid, y, x + 1, c); // right
        flood_fill(grid, y + 1, x, c); // down
        flood_fill(grid, y, x - 1, c); // left
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid[y].size(); x++)
            {
                if (grid[y][x] == '1')
                {
                    islands++;
                    flood_fill(grid, y, x, 'i');
                }
            }
        }
        return islands;
    }
};

int main()
{
    Solution *sol = new Solution();
}
