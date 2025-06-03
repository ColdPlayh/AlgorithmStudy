// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem73.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
// #include <stdc++.h>;
// using namespace std;
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //标记法
        // int col=matrix[0].size();
        // int row=matrix.size();
        // vector<int> rows(row),cols(col);
        // for(int i=0;i<row;i++)
        // {
        //     for(int j=0;j<col;j++)
        //     {
        //         if(matrix[i][j]==0)
        //         {
        //             rows[i]=true;
        //             cols[j]=true;
        //         }
        //     }
        // }
        // for(int i=0;i<row;i++)
        // {
        //     for(int j=0;j<col;j++)
        //     {
        //         if( rows[i] || cols[j])
        //         {
        //            matrix[i][j]=0;
        //         }
        //     }
        // }
        //原地修改数组
        int row=matrix.size();
        int col=matrix[0].size();
        
        bool colhave0=false;
        bool rowhave0=false;
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==0)
                colhave0=true;
            
        }
        for(int i=0;i<col;i++)
        {
            if(matrix[0][i]==0)
                rowhave0=true;
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        /*为什么只需要记录第一行和第一列是不是0，假如第一行[1,21,0,2]
        第三列 为[0,1,1,1]，是否会导致第三列不能被正确设置
        我们在遍历过程中，
        当前元素对应第一行和第一列的元素有任意一个为0则将其置为0
        */
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(rowhave0)
        {
            for(int i=0;i<col;i++)
            {
                matrix[0][i]=0;
            }
        }
         if(colhave0)
        {
            for(int i=0;i<row;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};
// @lc code=end

