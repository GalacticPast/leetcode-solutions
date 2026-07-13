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

class Node
{
  public:
    int   val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val    = _val;
        next   = NULL;
        random = NULL;
    }
};

class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        Node                      *temp = head;
        vector<Node *>             vec;
        unordered_map<Node *, int> map;

        int i = 1;
        vec.push_back(nullptr);
        while (temp)
        {
            map[temp]  = i++;
            Node *node = new Node(temp->val);
            vec.push_back(node);
            temp = temp->next;
        }
        temp = head;
        i    = 1;
        while (temp)
        {
            int n_node = 0;
            int r_node = 0;
            if (temp->next)
            {
                n_node = map[temp->next];
            }
            if (temp->random)
            {
                r_node = map[temp->random];
            }
            vec[i]->next   = vec[n_node - 1];
            vec[i]->random = vec[r_node - 1];
            i++;
        }
        return vec[1];
    }
};
int main()
{
    Solution *sol = new Solution();
}
