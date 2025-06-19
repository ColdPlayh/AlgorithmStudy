// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem145.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ans;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        while (cur || !stk.empty())
        {
            while (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (cur->right == nullptr || cur->right == prev)
            {
                ans.push_back(cur->val);
                prev = cur;
                cur = nullptr;
            }
            else
            {
                stk.push(cur);
                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end
