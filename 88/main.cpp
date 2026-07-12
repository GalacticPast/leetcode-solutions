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
using std::swap;
using std::unordered_map;
using std::vector;

class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int j = 0;
        for (int i = m; i < nums1.size(); i++)
        {
            nums1[i] = nums2[j++];
        }
        j = m;
        for (int i = 0; i < nums1.size() && j < n && i < j; i++)
        {
            if (nums1[i] > nums1[j])
            {
                swap(nums1[i], nums1[j]);
                j++;
            }
        }
    }
};

int main()
{
    Solution *sol = new Solution();
}
