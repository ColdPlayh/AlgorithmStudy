/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <vector>;
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //从左下角开始遍历
        //当matrix[i][j] >target 根据性质可知，从[i][j]到[i][n]都会比target大，所以舍弃改行
        //同理 当matrix[i][j] <target[0][j]到[i][j]都小于target 舍弃列
        //当等于时返回结果
        int row=matrix.size(),col=matrix[0].size();
        int i=row-1; int j=0;
        while(i>=0 && j<col)
        {
            //消除行
            if(matrix[i][j]>target)
                i--;
            else if(matrix[i][j]<target)
                j++;
            else if(matrix[i][j]==target)
                return true;
        }
        return false;
        
    }
};
// @lc code=end

