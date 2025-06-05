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
        // // 不满足要求的 onlogn o1
        //  int n = nums.size();
        // //排序 nlogn
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
        //     //从第二个开始判断当前的元素是否等于prev+1
        //     if (flag && nums[i] != prev + 1 && nums[i]!=prev)
        //     {
        //         return prev + 1;
        //     }
        //     //如果排序后的第一个元素大于1，可以直接得出结果
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
        // 关键在在于nums的长度为n 那么未出现的最小正整数 一定在[1,n+1]
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
        // // 如果一个数num小于n 就将nums[num-1](减1防止越界)设置为负数
        // for (int i = 0; i < n; i++)
        // {
        //     // 用绝对值，是因为我们会边标记边遍历，数组是无序的，
        //     // 防止误判因标记被改变的元素（负数，但原数据<n：需要标记原数据 负数,原数据>n:不应该标记）
        //     int num = abs(nums[i]);
        //     if (num <= n)
        //     {
        //         //保证设置为负数
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
        // // // 否者就是n+1
        // return n + 1;

        // 置换法
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            //将[1,n]且其数值-1对应的下标不等于自己（nums[i]!=nums[nums[i]-1]）,就将其放到自己应该所处的位置
            while(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1])
            {
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            //第一个数值不等于下标+1的元素 下标+1就是缺失的第一个正数
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
};
// @lc code=end
