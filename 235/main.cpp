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

struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->val < p->val && curr->val < q->val)
            {
                curr = curr->right;
            }
            else if (curr->val > p->val && curr->val > q->val)
            {
                curr = curr->left;
            }
            else
            {
                break;
            }
        }
        return curr;
    }
};

int main()
{
    Solution *sol = new Solution();
}
