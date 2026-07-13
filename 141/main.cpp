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
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast_node = head;
        ListNode *slow_node = head;

        while (fast_node)
        {
            fast_node = fast_node->next;
            if (fast_node == nullptr)
                return false;
            fast_node = fast_node->next;
            slow_node = slow_node->next;
            if (fast_node == slow_node)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution *sol = new Solution();
}
