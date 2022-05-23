// Source : https://leetcode-cn.com/problems/pascals-triangle/
// Author：GuoQiang Yao
// Date : 2021-09-21


/******************************************************************************************
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30

******************************************************************************************/


/*******************************************************************************************************

题目分析：简单分析一下就可以发现，杨辉三角的前两行比较特殊,需要特殊处理，如果使用If语句进行的话，
因为存在return的原因，并且每次都需要将每一行的首尾元素全部置为1，故应该在循环中使用一定的手法将首尾元素置为1。
对于中间的元素，我们需要使用杨辉三角的特点进行处理，即该元素是上一行左右元素的和。

********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //C++ 中创建一定元素数目的数组语法与C略有不同（使用的是圆括号而不是方括号）
        vector<vector<int>> tri(numRows);
        for (int i = 0; i < numRows; ++i) {
            tri[i].resize(i + 1);
            //杨辉三角中，每行第一个元素和最后一个元素都是1
            tri[i][0] = tri[i][i] = 1;
            //从第三行开始按照公式处理杨辉三角
            for (int j = 1; j < i; ++j) {
                //每一个元素都是上一行，同样位置左右的元素值之和
                tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
            }
        }
        return tri;
    }
};
