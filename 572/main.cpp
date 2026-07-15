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
    bool ans = false;

  public:
    bool check_tree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if ((p == nullptr && q) || (q == nullptr && p))
            return false;
        if (p->val != q->val)
            return false;
        bool left  = check_tree(p->left, q->left);
        bool right = check_tree(p->right, q->right);
        return left && right;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return true;
        if (ans)
            return true;
        if (root->val == subRoot->val && !ans)
        {
            bool a = check_tree(root, subRoot);
            ans    = a == true ? a : false;
        }
        isSubtree(root->left, subRoot);
        isSubtree(root->right, subRoot);
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
