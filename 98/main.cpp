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

void print_arr(vector<int> &a)
{
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}

class Solution
{
  public:
    void dfs(TreeNode *root, vector<int> &a)
    {
        if (!root)
            return;
        dfs(root->left, a);
        a.push_back(root->val);
        dfs(root->right, a);
    }
    bool isValidBST(TreeNode *root)
    {
        vector<int> a;
        dfs(root, a);

        for (int i = a.size() - 2; i >= 0; i--)
        {
            if (a[i] >= a[i + 1])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution *sol = new Solution();
}
