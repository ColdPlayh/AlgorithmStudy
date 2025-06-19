/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode *root)
    {
        // DFS
        //  if(root == nullptr) return 0;
        //  return max(maxDepth(root->left)+1,maxDepth(root->right)+1);
        // BFS
        if(root==nullptr) return 0;
        vector<TreeNode *> que;
        int ans = 0;
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
            }
            que=temp;
            ans += 1;
        }
        return ans;
    }
};
// @lc code=end
