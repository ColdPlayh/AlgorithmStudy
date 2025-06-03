/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <vector>;
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> temp=matrix;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[j][n-1-i]=temp[i][j];
            }
        }
        //先水平镜像 在按对角线镜像
    }
};
// @lc code=end

