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
    ListNode()
        : val(0), next(nullptr)
    {
    }
    ListNode(int x)
        : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next)
        : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    bool isPalindrome(ListNode *head)
    {
        stack<ListNode *> st;
        ListNode         *t = head;

        while (t)
        {
            st.push(t);
            t = t->next;
        }
        t = head;
        while (t)
        {
            ListNode *a = st.top();
            if (t->val != a->val)
            {
                return false;
            }
            st.pop();
            t = t->next;
        }
        return true;
    }
};

int main()
{
    Solution *sol = new Solution();
}
