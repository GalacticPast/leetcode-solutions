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
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
  public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if ((p == nullptr && q) || (q == nullptr && p))
            return false;
        if (p->val != q->val)
            return false;
        bool left  = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left && right;
    }
};
int main()
{
    Solution *sol = new Solution();
}
