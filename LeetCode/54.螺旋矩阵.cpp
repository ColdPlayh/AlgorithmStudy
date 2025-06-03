/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>;
#include <string>;
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int t=0,b=matrix.size()-1,l=0,r=matrix[0].size()-1;
        vector<int> ans;

        while(true)
        {
            for(int i=l;i<=r;i++) ans.push_back(matrix[t][i]);
            if(++t>b) break;
            for(int i=t;i<=b;i++) ans.push_back(matrix[i][r]);
            if(--r<l) break;
            for(int i=r;i>=l;i--) ans.push_back(matrix[b][i]);
            if(--b<t) break;
            for(int i=b;i>=t;i--) ans.push_back(matrix[i][l]);
            if(++l>r) break;
        }
        
        return ans;
    }
};
// @lc code=end

