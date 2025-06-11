/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */
#include <unordered_map>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// @lc code=start

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        //    Node* current=head;
        //    unordered_map<Node*,Node*> map;
        //    while(current)
        //    {
        //         map[current]=new Node(current->val);
        //         current=current->next;
        //    }

        //    current=head;
        //    while(current)
        //    {
        //         map[current]->next=map[current->next];
        //         map[current]->random=map[current->random];
        //         current=current->next;
        //    }
        //    return map[head];
        if(head==nullptr) return nullptr;
        Node *current = head;
        while (current)
        {
            //
            Node *newNode = new Node(current->val);
            newNode->next=current->next;
            current->next=newNode;
            current=current->next->next;
        }
        current=head;
        
        while(current)
        {
            //current.next就是current拷贝后的新节点
            current->next->random=current->random==nullptr ? nullptr: current->random->next;
            current=current->next->next;
        }

        current=head;
        Node *ans=current->next;
        while(current)
        {
            Node* newNode=current->next;
            current->next=current->next->next;
            
            newNode->next=newNode->next==nullptr ? nullptr : newNode->next->next;
            current=current->next;
        
        }
        return ans;
    }
};
// @lc code=end
