/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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

#include <vector>
#include <queue>
using namespace std;

class Solution
{

public:
    struct compare
    {
        bool operator()(const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, compare> queue;
        ListNode dummy;
        ListNode *ans = &dummy;
        for (auto head : lists)
        {
            if (head)
                queue.push(head);
        }
        ListNode *cur;
        while (!queue.empty())
        {
            cur = queue.top();
            queue.pop();
            if (cur->next)
                queue.push(cur->next);
            ans->next = cur;
            ans = ans->next;
        }
        return dummy.next;
    }
};
// @lc code=end
