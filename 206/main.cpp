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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        stack<ListNode *> st;

        while (head)
        {
            st.push(head);
            head           = head->next;
            st.top()->next = nullptr;
        }

        head             = st.top();
        ListNode *t_head = st.top();
        st.pop();
        while (!st.empty())
        {
            auto ptr     = st.top();
            t_head->next = ptr;
            t_head       = ptr;
            st.pop();
        }
        return head;
    }
};

int main()
{
    Solution *sol = new Solution();
}
