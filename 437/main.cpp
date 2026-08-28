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
    int dfs(TreeNode *root, int target_sum, long long sum)
    {
        if (!root)
            return 0;
        sum     += root->val;
        int ans  = target_sum == sum ? 1 : 0;
        ans     += dfs(root->left, target_sum, sum);
        ans     += dfs(root->right, target_sum, sum);
        return ans;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        return dfs(root, targetSum, 0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};

int main()
{
    Solution *sol = new Solution();
}
