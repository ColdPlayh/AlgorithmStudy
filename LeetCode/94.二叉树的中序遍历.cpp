// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem94.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution
{
public:
    // vector<int> ans;
    vector<int> inorderTraversal(TreeNode *root)
    {
        // 递归
        //  if (root == nullptr)
        //      return {};

        // inorderTraversal(root->left);
        // ans.push_back(root->val);
        // inorderTraversal(root->right);
        // return ans;
        // 迭代

        if (root == nullptr)
            return {};
        stack<TreeNode *> stk;
        vector<int> ans;
        TreeNode *cur = root;
        while (cur != nullptr || !stk.empty())
        {
            while (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};
// @lc code=end
