#include "algorithm"
#include "iostream"
#include "stack"
#include "unordered_map"
#include "utility"
#include "vector"

using std::cout;
using std::endl;
using std::pair;
using std::sort;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

class TimeMap
{
    unordered_map<string, vector<pair<string, int>>> map;

  public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        auto kvp = map.find(key);
        if (kvp != map.end())
        {
            kvp->second.push_back({value, timestamp});
        }
        else
        {
            map.insert({key, {{value, timestamp}}});
        }
    }

    string get(string key, int timestamp)
    {
        auto kvp = map.find(key);
        if (kvp == map.end())
            return "";
        auto vec = kvp->second;

        int left  = 0;
        int right = vec.size();

        while (left <= right)
        {
            int  mid  = left + (right - left) / 2;
            auto pair = vec[mid];
            if (pair.second == timestamp)
            {
                return pair.first;
            }
            else if (pair.second > timestamp)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return "";
    }
};

int main()
{
    TimeMap *sol = new TimeMap();
}
