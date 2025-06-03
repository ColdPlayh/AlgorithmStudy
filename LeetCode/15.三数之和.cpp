/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());

        set<vector<int>> ans;

        for(int i=0;i<n-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;
            int target=-nums[i];
            while(l<r)
            {
                int sum=nums[l]+nums[r];
                if(sum==target)
                {
                    ans.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r&&nums[l]==nums[l-1]) l++;
                    while(l<r&&nums[r]==nums[r+1]) r--;
                }
                else if(sum>target)
                {
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return vector<vector<int>> {ans.begin(),ans.end()};
    }
};
// @lc code=end

