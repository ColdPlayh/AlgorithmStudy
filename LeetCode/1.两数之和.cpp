// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
using namespace std;

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

// @lc code=start
class Solution {
public:
    unordered_map<int, int> map;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            if(map.find(target-nums[i])!=map.end()){
                return {map[target-nums[i]],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};
// @lc code=end

