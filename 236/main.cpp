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

struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
    TreeNode *node;

  public:
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
        {
            return false;
        }
        bool left  = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        bool mid   = (root == p || root == q);

        if (left && right || left && mid || right && mid)
        {
            node = root;
        }
        return mid || left || right;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return node;
    }
};

int main()
{
    Solution *sol = new Solution();
}
