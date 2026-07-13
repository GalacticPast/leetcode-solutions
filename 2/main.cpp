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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode  *n_head     = nullptr;
        ListNode **temp       = &n_head;
        int        carry_over = 0;
        while (l1 && l2)
        {
            int sum        = (l1->val + l2->val + carry_over) % 10;
            carry_over     = (l1->val + l2->val + carry_over) / 10;
            ListNode *node = new ListNode(sum);
            *temp          = node;
            temp           = &(node->next);

            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int sum        = (l1->val + carry_over) % 10;
            carry_over     = (l1->val + carry_over) / 10;
            ListNode *node = new ListNode(sum);
            *temp          = node;
            temp           = &(node->next);

            l1 = l1->next;
        }
        while (l2)
        {
            int sum        = (l2->val + carry_over) % 10;
            carry_over     = (l2->val + carry_over) / 10;
            ListNode *node = new ListNode(sum);
            *temp          = node;
            temp           = &(node->next);

            l2 = l2->next;
        }
        if (carry_over)
        {
            ListNode *node = new ListNode(carry_over);
            *temp          = node;
            temp           = &(node->next);
        }
        return n_head;
    }
};

int main()
{
    Solution *sol = new Solution();
}
