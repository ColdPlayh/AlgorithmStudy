/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include <stdc++.h>;
using namespace std;
// @lc code=start
class Solution
{
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        // 利用中间数组 on on
        // int n = nums.size();
        // vector<int> temp(n);
        // for (int i = 0; i < n; i++)
        // {
        //     temp[(i + k) % n] = nums[i];
        // }
        // nums.assign(temp.begin(), temp.end());
        // 反转数组
        // k %=nums.size();
        // reverse(nums,0,nums.size()-1);
        // reverse(nums,0,k-1);
        // reverse(nums,k,nums.size()-1);
        // 原地交换
        int n = nums.size();
        k %= n;
        int count = gcd(k, n);

        for (int start = 0; start < count; start++)
        {
            int current = start;
            int prev = nums[start];
            do
            {
                int next=(current+k)%n;
                swap(prev,nums[next]);
                current=next;
            }
            while(start!=current);
        }
    }
};
// @lc code=end
