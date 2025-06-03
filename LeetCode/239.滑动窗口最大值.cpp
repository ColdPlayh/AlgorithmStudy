// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem239.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <vector>
#include <queue>
#include <stdc++.h>;
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> queue;
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            queue.emplace(make_pair(nums[i],i));
        }
        ans.emplace_back(queue.top().first);
        for(int i=k;i<n;i++)
        {
            queue.emplace(make_pair(nums[i],i));
            while(!queue.empty()&&queue.top().second<=i-k)
            {
                queue.pop();
            }
            ans.emplace_back(queue.top().first);
        }
        return ans;

    }
};
// @lc code=end

