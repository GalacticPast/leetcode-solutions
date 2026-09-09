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
    void dfs(vector<int> &ans, TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(ans, root->left);
        ans.push_back(root->val);
        dfs(ans, root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
}
