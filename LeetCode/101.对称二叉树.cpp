/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <queue>
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
    bool isSymmetric(TreeNode *root)
    {
        // return root==nullptr || recur(root->left,root->right);
        // 迭代
        queue<TreeNode *> que;

        TreeNode *l = root->left;
        TreeNode *r = root->right;
        que.push(l);
        que.push(r);
        while (!que.empty())
        {
            l = que.front();
            que.pop();
            r = que.front();
            que.pop();
            if(l==nullptr && r==nullptr) continue;
            if (l == nullptr || r==nullptr || l->val != r->val)
                return false;
            que.push(l->left);
            que.push(r->right);
            que.push(l->right);
            que.push(r->left);
        }
        return true;
    }
    bool recur(TreeNode *l, TreeNode *r)
    {
        if (l == nullptr && r == nullptr)
            return true;
        if (l == nullptr || r == nullptr || l->val != r->val)
            return false;
        return recur(l->left, r->right) && recur(l->right, r->left);
    }
};
// @lc code=end
