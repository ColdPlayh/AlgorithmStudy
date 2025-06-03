// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem234.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// #include <stdc++.h>;
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *frontNode;
    bool recursivelyCheck(ListNode *curr)
    {
        if(curr!=nullptr)
        {
            if(!recursivelyCheck(curr->next))
            {
                return false;
            }
            if(frontNode->val!=curr->val)
            {
                return false;
            }
            frontNode=frontNode->next;
        }
        return true;

    }
    ListNode * findMiddleNode(ListNode * head)
    {
        ListNode *s=head,*f=head;
        //快的不出问题，慢的就不会出问题
        while(f->next!=nullptr && f->next->next!=nullptr)
        {
            s=s->next;
            f=f->next->next;
        }
        return s;
    }

    ListNode * reverseListNode(ListNode * head)
    {
        ListNode *curr=head;
        ListNode *pre=nullptr;

        while(curr!=nullptr)
        {
            ListNode* next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        return pre;

    }
    bool isPalindrome(ListNode *head)
    {
        //复制 on on
        // ListNode *H =head;
        // vector<int> v;
        // while(H!=nullptr)
        // {
        //     v.push_back(H->val);
        //     H=H->next;
        // }
        // for(int i=0,j=v.size()-1;i<j;i++,j--)
        // {
        //     if(v[i]!=v[j]) return false;
        // }
        // return true;
        
        //递归 on on
        // frontNode=head;
        // return recursivelyCheck(head);

        ListNode * middle=findMiddleNode(head);
        ListNode * reverse= reverseListNode(middle->next);
    
        while(head!=nullptr && reverse!=nullptr)
        {
            if(head->val!=reverse->val)
            {
                return false;
            }
            head=head->next;
            reverse=reverse->next;
        }
        ListNode * recover =reverseListNode(reverse);
        return true;

    }
};
// @lc code=end
