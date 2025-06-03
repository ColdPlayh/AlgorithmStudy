/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#include <stdc++.h>;
using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next==nullptr || head->next->next==nullptr)
            return nullptr;

        
        ListNode *s = head, *f = head, *cnode = nullptr;

        while (true)
        {
            if (f == nullptr || f->next == nullptr) return nullptr;
            s = s->next;
            f = f->next->next;
            if (s == f)
                break;
        }
        f = head;
        while (f != s)
        {
            s = s->next;
            f = f->next;
        }
        return s;
    }
};
// @lc code=end
