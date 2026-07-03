#include "iostream"
#include "string"
#include "unordered_set"
#include "vector"

using std::string;
using std::unordered_set;
using std::vector;

class Solution
{
  public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int k = 1;
        while (true)
        {
            int t = 0;
            for (int i : piles)
            {
                t += ceil(i / k);
            }
            std::cout << t << " ";
            if (t <= h)
            {
                return k;
            }
            k++;
        }
        return -1;
    }
};
