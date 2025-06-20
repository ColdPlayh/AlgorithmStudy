/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
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

class Solution
{
    vector<int> ans;

public:
    vector<int> preorder(Node *root)
    {
        // dfs
        //  if(root==nullptr) return{};
        //  dfs(root);
        //  return ans;
        // 栈模拟
        // if (root == nullptr)
        //     return {};
        // vector<int> ans;
        // unordered_map<Node *, int> cnt;
        // stack<Node *> st;
        // Node *cur = root;
        // while (cur || !st.empty())
        // {
        //     while (cur)
        //     {
        //         ans.push_back(cur->val);
        //         st.emplace(cur);
                    //不断像左遍历
        //         if (cur->children.size() > 0)
        //         {
                        //记录当前节点遍历过的子节点的index
        //             cnt[cur] = 0;
        //             cur = cur->children[0];
        //         }
        //         else
        //         {
        //             cur = nullptr;
        //         }
        //     }
        //     cur = st.top();
        //     // 下一个要遍历的子节点
        //     int nextIndex = (cnt.count(cur) ? cnt[cur] : -1) + 1;
                //如果下一个要遍历的子节点存在
        //     if (nextIndex < cur->children.size())
        //     {
                    //记录最新遍历过的节点
        //         cnt[cur] = nextIndex;
        //         cur = cur->children[nextIndex];
        //     }
                //当前节点没有子节点或节点全被遍历过，出栈
        //     else
        //     {
        //         st.pop();
        //         cnt.erase(cur);
                    //防止死循环
        //         cur = nullptr;
        //     }
        // }
        // return ans;

        // 迭代优化
        if (root == nullptr)
            return {};
        vector<int> ans;
        stack<Node *> st;
        st.emplace(root);
        while(!st.empty())
        {
            root=st.top();
            st.pop();
            ans.push_back(root->val);
            //从右往左入栈（先进后出）
            for(auto it=root->children.rbegin();it!=root->children.rend();it++)
            {
                st.emplace(* it);
            }

        }
        return ans;
    }
    void dfs(Node *node)
    {
        if (node == nullptr)
            return;
        ans.push_back(node->val);
        for (auto lt : node->children)
        {
            dfs(lt);
        }
    }
};
// @lc code=end
