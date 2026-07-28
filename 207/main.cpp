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
    bool cycle = false;

  public:
    bool check_cycle(vector<vector<int>> &adj, vector<int> &state, int node)
    {
        if (state[node] == 1)
            return true;
        if (state[node] == 2)
            return false;

        state[node] = 1;

        for (int i : adj[node])
        {
            if (check_cycle(adj, state, i))
            {
                return true;
            }
        }
        state[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);

        for (auto &vec : prerequisites)
        {
            adj[vec[1]].push_back(vec[0]);
        }

        vector<int> state(numCourses);

        for (int i = 0; i < numCourses; i++)
        {
            if (state[i] == 0)
            {
                if (check_cycle(adj, state, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution *sol = new Solution();
}
