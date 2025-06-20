/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
class Solution {
    private:
    int ans;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //记录的是最大路径（节点数）
        ans=1;
        depth(root);
        //返回的是最大直径需要-1 例如最长路径包含五个节点，事实上他的直径是4
        return ans-1;
    }
    int depth(TreeNode* node)
    {
        if(node ==nullptr) return 0;
        int ld=depth(node->left);
        int rd=depth(node->right);
        ans=max(ans,ld+rd+1);
        return max(ld,rd)+1;

    }
    int max(int a,int b)
    {
        if(a>b) return a;
        else return b;
    }
};
// @lc code=end

