/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <stdc++.h>;
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();
        if(n<=0)
        {
            return {};
        }
        int i=0;
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        
        while(i<n)
        {
            int l=intervals[i][0];
            //默认最大为右边界
            int top=intervals[i][1];
            int j=i+1;
            while(j<n&&intervals[j][0]<=top)
            {
                top=max(top,intervals[j][1]);
                j++;
            }
            i=j;
            ans.push_back({l,top});
        }
        return ans;
    }
};
// @lc code=end

