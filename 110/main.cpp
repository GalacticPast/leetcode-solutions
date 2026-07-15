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
    bool ans = true;

  public:
    int get_height(TreeNode *root)
    {
        if (ans == false || root == nullptr)
            return 0;
        int left  = get_height(root->left) + 1;
        int right = get_height(root->right) + 1;
        if (abs(left - right) > 1)
        {
            ans = false;
            return 0;
        }
        return max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        int l_h = get_height(root->left) + 1;
        int r_h = get_height(root->right) + 1;
        if (abs(l_h - r_h) > 1)
        {
            ans = false;
        }
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
