/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *head2 = FindMiddleNode(head);

        head = sortList(head);
        head2 = sortList(head2);
        return Merge(head, head2);
    }

    ListNode *FindMiddleNode(ListNode *head)
    {
        ListNode *pre = head;
        ListNode *slow=head ,*fast = head;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return slow;
    }
    ListNode *Merge(ListNode *list1, ListNode *list2)
    {
        ListNode dummy;
        ListNode *cur = &dummy;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1==nullptr ? list2: list1;
        return dummy.next;
    }
};
// @lc code=end
