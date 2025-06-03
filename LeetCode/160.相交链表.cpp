/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

 #include <stdc++.h>;
 #include <map>;
 #include <set>;
 using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_set<ListNode *> visited;
        // ListNode* temp=headA;
        // while (temp!=nullptr)
        // {
        //     visited.
        // }
        ListNode * A=headA;
        ListNode * B=headB;
        while(A!=B)
        {
            A=A == nullptr ? headB : A->next;
            B=B == nullptr ? headA : B->next;
        }
        return A;
        
    }
};
// @lc code=end

