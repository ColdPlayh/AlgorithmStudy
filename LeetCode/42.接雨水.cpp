// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        /*
            动态规划
        */
        // int n = height.size();
        // if (n == 0)
        // {
        //     return 0;
        // }
        // vector<int> leftMax(n);
        // leftMax[0] = height[0];
        // for (int i = 1; i < n; ++i)
        // {
        //     leftMax[i] = max(leftMax[i - 1], height[i]);
        // }

        // vector<int> rightMax(n);
        // rightMax[n - 1] = height[n - 1];
        // for (int i = n - 2; i >= 0; --i)
        // {
        //     rightMax[i] = max(rightMax[i + 1], height[i]);
        // }

        // int ans = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     ans += min(leftMax[i], rightMax[i]) - height[i];
        // }
        // return ans;
        /*
            单调栈
         */

        /* 双指针解法
        注意到动态规划中
        对于位置 i 的接水量取决于 leftMax 和 rightMax 中的较小者
        所以我们不必真的知道较大者是谁
        只要知道较小者是谁就可以了

        初始化 left = 0, right = n-1, leftMax = 0, rightMax = 0
        对于位置 left 来说, leftMax 是其真正的左侧最大值, 而 rightMax 不是其真正的右侧最大值,因为区间（left, right）的值还没有遍历，
        但可以确定的是，left的rightMax一定>= right的rightmax
        同理，对于位置 right 来说, rightMax 是真的右侧最大值, 而 leftMax 不是其真正的左侧最大值，因为区间（left, right）的值还没有遍历，
        但让然可以确定，right的leftMax一定>=left的leftMax

        那么，以位置left为例：
        1. 使用 height[left] 和 height[right] 得到 leftMax和rightMax
        2. 若 leftMax < rightMax, 则说明对于left 来说,
             leftMax 一定小于其右侧真正意义上的最大值，
             因为leftMax<[right,n]的局部最大值, 更比不过包含（left，right）区间的真正的rightMax
             而我们计算当前柱子的充水量只需要知道较小的边界即可，所以冲水量为leftMax - height[left]
        3. 类似地处理 rightMax >= leftMax 的情况
        */
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right)
        {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (leftMax < rightMax)
            {
                ans += leftMax - height[left];
                ++left;
            }
            else
            {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};
// @lc code=end
