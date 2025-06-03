// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem41.h"

// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        // 不满足要求的 onlogn o1
        //  int n = nums.size();

        // sort(nums.begin(), nums.end());
        // if (nums[n - 1] < 1 || nums[0]>1)
        //     return 1;

        // int i = 0;
        // int prev;
        // bool flag=false;
        // while (i < n)
        // {
        //     if (nums[i] < 1)
        //     {
        //         i++;
        //         continue;
        //     }
        //     if (flag && nums[i] != prev + 1 && nums[i]!=prev)
        //     {
        //         return prev + 1;
        //     }
        //     if (!flag)
        //     {
        //         if(nums[i]>1) return 1;
        //         flag = true;
        //     }
        //     prev = nums[i];
        //     i++;
        // }
        // return nums[n - 1] + 1;

        // 标记法
        // 有点不像人能想出来的方法，关键在在于nums的长度为n 那么未出现的最小正整数 一定在[1,n+1]
        // 如果[1,n]都出现了 那么最小正整数一定是n+1
        // 如果[1,n]没有都出现，那么最小正整数一定在[1,n]之间
        // int n = nums.size();
        // // 将所有的负数转化为正数且设置为n+1
        // for (int &num : nums)
        // {
        //     if (num <= 0)
        //     {
        //         num = n + 1;
        //     }
        // }
        // // 如果一个数小于n 就将其对应下标（-1 防止越界）设置为负数
        // for (int i = 0; i < n; i++)
        // {
        //     // 用绝对值，是因为我们会边标记边遍历，数组是无序的，防止误判标记过的元素（负数，但原数据可能大于n）
        //     int num = abs(nums[i]);
        //     if (num <= n)
        //     {
        //         nums[num - 1] = -abs(nums[num - 1]);
        //     }
        // }
        // // 第一个不是负数的下标+1就是最小正整数
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] > 0)
        //     {
        //         return i + 1;
        //     }
        // }
        // // 否者就是n+1
        // return n + 1;

        //置换法
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            
            while(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1])
            {
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
};
// @lc code=end
