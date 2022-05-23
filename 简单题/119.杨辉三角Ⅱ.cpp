// Source : https://leetcode-cn.com/problems/pascals-triangle-ii/
// Author ：GuoQiang Yao
// Date : 2021-09-23


/**************************************************************************************
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 33
 

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

**************************************************************************************/



/*******************************************************************************************************

题目分析： 该题与杨辉三角类似，但是上一个杨辉三角是需要我们返回前 n 行，
然而现在的题目是要求我们返回第 n 行，因此外层 for 循环的判断条件需要格外注意，
当把循环条件从 ≤ 换为 ＜ 的时候，运行速度会快很多。如果有大佬知道缘由，还请不吝赐教。
然后按照之前的代码进行编写即可，最后返回的时候需要返回第 n 行即可。
之前的代码：https://github.com/intellectual-yao/my-leetcode/blob/main/118.%E6%9D%A8%E8%BE%89%E4%B8%89%E8%A7%92.cpp

********************************************************************************************************/


class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        //定义一个二维数组
        vector<vector<int>> my_arr(10000);
        //因为本题需要返回当前某行的元素，因此循环判断条件需要注意，
        //但是如果换成注释掉的语句，速度会快很多
        
        //for(int i = 0;i < rowIndex + 1; ++i)
        for(int i = 0;i <= rowIndex; ++i)
        {
            //行数必须从0开始，因此要将当前行（第i行）的元素数置为i + 1
            my_arr[i].resize(i + 1);
            //二位数组每行第一位和最后一位置为1
            my_arr[i][0] = my_arr[i][i] = 1;
            for(int j = 1;j < i;++j)
            {
                //计算第三行开始的中间位置上的元素的值
                my_arr[i][j] = my_arr[i - 1][j - 1] + my_arr[i - 1][j];
            }
        }
        //返回特定行的元素
        return my_arr[rowIndex];
    }
};
