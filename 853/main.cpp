#include "algorithm"
#include "iostream"
#include "stack"
#include "utility"
#include "vector"

using std::cout;
using std::endl;
using std::pair;
using std::sort;
using std::stack;
using std::vector;

void print_pairs(vector<pair<int, int>> &vec)
{
    for (auto p : vec)
    {
        cout << p.first << ":" << p.second << "   ";
    }
    cout << endl;
}

class Solution
{
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int                    n = position.size();
        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), [](const auto &a, const auto &b) {
            return a.first > b.first;
        });

        stack<float> st;

        for (auto p : cars)
        {
            float t = (float)(target - p.first) / p.second;

            if (st.empty() || (!st.empty() && t > st.top()))
            {
                st.push(t);
            }
        }
        return st.size();
    }
};

int main()
{
    vector<int> pos   = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    Solution *sol = new Solution();

    int ans = sol->carFleet(12, pos, speed);
    cout << ans << endl;
}
