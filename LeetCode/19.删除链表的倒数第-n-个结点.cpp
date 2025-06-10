/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <stdc++.h>;
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //哑节点 主要是防止cur.next为null ，导致无法获取cur.next.next
        ListNode *dummy =new ListNode(0,head);
        ListNode *pre=head,*cur=dummy;
        //前指针移动n次
        while(n--)
            pre=pre->next;
        while(pre)
        {
            pre=pre->next;
            cur=cur->next;
        }
        //当前指针为null时，cur的next就是要删除的节点
        ListNode *needMove = cur->next;
        cur->next=cur->next->next;
        //删除中间节点
        delete needMove;
        
        //结果
        ListNode * ans =dummy->next;
        delete dummy;
        return ans;

    }
};
// @lc code=end

