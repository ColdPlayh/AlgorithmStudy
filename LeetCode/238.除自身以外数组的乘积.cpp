/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <stdc++.h>;
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n=nums.size();
        vector<int> ans(n);
        int tail=1;
        //保证前缀和计算正确
        ans[0]=1;
        for(int i=1;i<n;i++)
        {
            ans[i]=nums[i-1]*ans[i-1];
        }
        //到倒数第二个开始，因为ans[i],恰巧就是prev[i]
        for(int i=n-2;i>=0;i--)
        {
            //后缀和
            tail *=nums[i+1];
            //前缀和*后缀和得到结果复制到当前的元素
            ans[i]=tail*ans[i];
        }
        return ans;
    }
};
// @lc code=end
