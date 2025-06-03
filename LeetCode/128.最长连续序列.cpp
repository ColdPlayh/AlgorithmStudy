/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    unordered_set<int> set;
    int maxTrack = 0;
    int longestConsecutive(vector<int> &nums)
    {
        for (const int &num : nums)
        {
            set.insert(num);
        }
        for (const int &num : set)
        {
            if (!set.count(num - 1))
            {
                int currentNum = num;
                int currentTrack = 1;
                while (set.count(num + 1))
                {
                    currentNum++;
                    currentTrack++;
                }
                maxTrack = max(currentTrack, maxTrack);
            }
        }
        return maxTrack;
    }
};
// @lc code=end
