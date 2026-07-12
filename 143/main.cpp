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

struct ListNode
{
    int       val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};
class Solution
{
  public:
    void reorderList(ListNode *head)
    {
        vector<ListNode *> vec;
        ListNode          *temp = head;
        while (temp)
        {
            vec.push_back(temp);
            temp = temp->next;
        }
        int left  = 0;
        int right = vec.size() - 1;

        while (left < right)
        {
            vec[left]->next  = vec[right];
            vec[right]->next = vec[left + 1];
            right--;
            left++;
        }
        vec[left]->next = nullptr;
    }
};

int main()
{
    Solution *sol = new Solution();
}
