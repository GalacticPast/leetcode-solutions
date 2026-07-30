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

struct ListNode
{
    int       val;
    ListNode *next;
    ListNode(int x)
        : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> set;
        while (headA)
        {
            set.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (set.find(headB) != set.end())
            {
                return headB;
            }
            headB = headB->next;
        }

        return nullptr;
    }
};

int main()
{
    Solution *sol = new Solution();
}
