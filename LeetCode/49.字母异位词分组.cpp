// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem49.h"

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(auto s:strs)
        {
            string temp=s;
            sort(temp.begin(),temp.end());
            map[temp].emplace_back(s);
        }
        vector<vector<string>> res;
        for(auto it=map.begin();it!=map.end();++it)
        {
            res.emplace_back(it->second);
        }
        return res;
       
    }
};
// @lc code=end

