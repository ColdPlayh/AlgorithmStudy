/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
private:
    vector<int> ans;

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // if (root == nullptr)
        //     return {};

        // ans.push_back(root->val);
        // preorderTraversal(root->left);
        // preorderTraversal(root->right);
        // return ans;
        if (root == nullptr)
            return {};
        stack<TreeNode *> stk;
        vector<int> ans;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node= stk.top(); stk.pop();
            ans.push_back(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left); 
        }
        return ans;
    }
};
// @lc code=end
