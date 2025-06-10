/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode *swapPairs(ListNode *head)
    {

        ListNode* dummy =new ListNode(0,head);
        // if(dummy->next==nullptr || dummy->next->next == nullptr) return head;
        ListNode* ans= dummy;
        while(dummy->next && dummy->next->next)
        {
            ListNode *temp=dummy->next;
            ListNode *temp2=dummy->next->next->next;
            dummy->next=dummy->next->next;
            dummy->next->next=temp;
            temp->next=temp2;
            
            dummy=dummy->next->next;
        }
        return ans->next;
        
    }
};
// @lc code=end
