/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre=dummy, *end = dummy;
        while (end)
        {
            for (int i = 0; i < k && end != nullptr; i++)
                end = end->next;
            if (end == nullptr)
                break;
            ListNode *start = pre->next;
            ListNode *next = end->next;
            end->next = nullptr;
            pre->next = reverse(start);
            start->next = next;
            pre = start;
            end = start;
        }
        return dummy->next;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};
// @lc code=end
