#include "algorithm"
#include "cmath"
#include "iostream"
#include "queue"
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
using std::queue;
using std::sort;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{

  public:
    bool is_mirror(TreeNode *l, TreeNode *r)
    {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        if (l->val != r->val)
            return false;
        bool left  = is_mirror(l->left, r->right);
        bool right = is_mirror(l->right, r->left);
        return left && right;
    }
    bool isSymmetric(TreeNode *root)
    {
        return is_mirror(root->left, root->right);
    }
};

int main()
{
    Solution *sol = new Solution();
}
