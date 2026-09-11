#include "algorithm"
#include "climits"
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
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;

void print_arr(vector<pair<int, int>> &vec)
{
    for (auto p : vec)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    cout << endl;
}

class Solution
{
  public:
    vector<int> partitionLabels(string s)
    {
        vector<int> min_arr(26, INT_MAX);
        vector<int> max_arr(26, INT_MIN);

        for (int i = 0; i < s.size(); i++)
        {
            char c           = s[i];
            min_arr[c - 'a'] = min(i, min_arr[c - 'a']);
            max_arr[c - 'a'] = max(i, max_arr[c - 'a']);
        }

        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; i++)
        {
            if (min_arr[i] == INT_MAX)
                continue;
            cout << (char)('a' + i) << ":" << min_arr[i] << ":" << max_arr[i] << endl;
            intervals.push_back({min_arr[i], max_arr[i]});
        }
        std::sort(intervals.begin(), intervals.end());

        for (int j = 0; j < intervals.size(); j++)
        {
            if (intervals[j].first == -1)
                continue;
            auto pair = &intervals[j];
            for (int i = j + 1; i < intervals.size(); i++)
            {
                if (intervals[i].first > pair->second)
                    break;
                if (intervals[i].first < pair->first && intervals[i].second < pair->second)
                {
                    pair->first         = intervals[i].first;
                    pair->second        = max(intervals[i].second, pair->second);
                    intervals[i].first  = -1;
                    intervals[i].second = -1;
                }
                else if (intervals[i].first > pair->first && intervals[i].first < pair->second)
                {
                    pair->second        = max(intervals[i].second, pair->second);
                    intervals[i].first  = -1;
                    intervals[i].second = -1;
                }
                else if (intervals[i].first < pair->first && intervals[i].second > pair->second)
                {
                    pair->first         = intervals[i].first;
                    pair->second        = max(intervals[i].second, pair->second);
                    intervals[i].first  = -1;
                    intervals[i].second = -1;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i].first == -1)
                continue;
            ans.push_back(intervals[i].second - intervals[i].first + 1);
        }

        return ans;
    }
};

int main()
{
    Solution   *sol = new Solution();
    vector<int> ans = sol->partitionLabels("ababcbacadefegdehijhklij");
    for (int i : ans)
    {
        cout << i << endl;
    }
}
