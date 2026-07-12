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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> vec;
        ListNode          *temp = head;
        while (temp)
        {
            vec.push_back(temp);
            temp = temp->next;
        }
        int s = vec.size();
        if (s < n)
        {
            return nullptr;
        }
        int ind = s - n;
        if (ind == 0)
        {
            vec[0]->next = nullptr;
            head         = s > 1 ? vec[1] : nullptr;
        }
        else if (ind + 1 == s)
        {
            vec[ind - 1]->next = nullptr;
        }
        else
        {
            vec[ind - 1]->next = vec[ind + 1];
        }
        return head;
    }
};

int main()
{
    Solution *sol = new Solution();
}
