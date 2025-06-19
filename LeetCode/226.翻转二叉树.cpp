/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */
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
#include <vector>
using namespace std;
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // 递归
        //  if(root==nullptr) return nullptr;
        //  TreeNode* temp=root->left;
        //  root->left=invertTree(root->right);
        //  root->right=invertTree(temp);
        //  return root;
        // 迭代（层序遍历）
        if (root == nullptr)
            return nullptr;
        vector<TreeNode *> que;
        que.push_back(root);
        while (!que.empty())
        {

            vector<TreeNode*> temp;
            for (TreeNode *node : que)
            {
                if (node->left)
                    temp.push_back(node->left);
                if (node->right)
                    temp.push_back(node->right);
                TreeNode* tem= node->left;
                node->left=node->right;
                node->right=tem;
            }
            que=temp;
        }
        return root;
    }
};
// @lc code=end
