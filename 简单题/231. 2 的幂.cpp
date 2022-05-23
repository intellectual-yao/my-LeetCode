// Source : https://leetcode.cn/problems/count-largest-group/
// Author : GuoQiang Yao
// Date : 2022-5-10

/**************************************************************************************
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

示例 1：

输入：n = 1
输出：true
解释：20 = 1
示例 2：

输入：n = 16
输出：true
解释：24 = 16
示例 3：

输入：n = 3
输出：false
示例 4：

输入：n = 4
输出：true
示例 5：

输入：n = 5
输出：false

提示：

-23^ 1 <= n <= 23^1 - 1

**************************************************************************************/

/*******************************************************************************************************
题目分析： 此类题目可以注意看提示信息，可以采用32次的循环，判断 2 这个数字是否可以通过乘幂达到给定的数字，如果可以的话返回true即可。
********************************************************************************************************/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 0;i < 34;++i)
        {
            if(pow(2, i) == n)
                return true;
        }
        return false;
    }
};
