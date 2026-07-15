#include "algorithm"
#include "iostream"
#include "queue"
#include "stack"
#include "unordered_map"
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
    void bfs(TreeNode *root, vector<vector<int>> &ans)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int         n = q.size();
            vector<int> l;
            while (n--)
            {
                TreeNode *node = q.front();
                l.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }
            ans.push_back(l);
        }
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        bfs(root, ans);
        return ans;
    }
};
int main()
{
    Solution *sol = new Solution();
}
