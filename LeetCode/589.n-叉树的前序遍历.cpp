/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */
#include<vector>
#include<stack>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> ans;
public:
    vector<int> preorder(Node* root) {
        if(root==nullptr) return{};
        dfs(root);
        return ans;
    } 
    void dfs(Node *node)
    {
        if(node==nullptr) return;
        ans.push_back(node->val);
        for(auto lt:node->children)
        {
            dfs(lt);
        }
    }
};
// @lc code=end

