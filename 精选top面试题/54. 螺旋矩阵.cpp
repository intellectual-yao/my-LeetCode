// Source : https://leetcode.cn/problems/spiral-matrix/
// Author : GuoQiang Yao
// Date : 2022-6-13
/**************************************************************************************
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：



输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

**************************************************************************************/

/*******************************************************************************************************
题目分析： 本题的思路还是很巧，从外侧按照题目要求开始遍历，需要注意的地方均已经在代码中给出注释，
每一次遍历结束之后都要对相应的遍历变量进行相应的增减操作，如果不符合要求的话循环就要退出。
********************************************************************************************************/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) 
            return res;
        // 首先对四个边界进行界定
        int up = 0;
        // 注意，这里必须减一，否则在最右侧循环以及最下侧循环的时候会报错
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while(true)
        {
            // 从左向右遍历
            for(int i = left;i <= right;++i)
                res.push_back(matrix[up][i]);
            // 遍历结束之后向下移动一行
            ++up;
            // 如果up大于down的话就退出
            if(up > down)
                break;
            // 从上向下遍历
            for(int i = up;i <= down;++i)
                res.push_back(matrix[i][right]);
            // 遍历结束之后右边界向左移动
            --right;
            // 如果右边界小于左边界就退出
            if(right < left)
                break;
            // 从右向左遍历
            for(int i = right;i >= left;--i)
                res.push_back(matrix[down][i]);
            --down;
            if(down < up)
                break;
            // 从下向上遍历
            for(int i = down;i >= up;--i)
                res.push_back(matrix[i][left]);
            ++left;
            if(left > right)
                break;
        }
        return res;
    }
};  
