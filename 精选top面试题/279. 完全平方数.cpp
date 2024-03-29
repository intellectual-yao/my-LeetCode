// Source :https://leetcode.cn/problems/perfect-squares/
// Author : GuoQiang Yao
// Date : 2022-11-21
/**************************************************************************************
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：

输入：n = 12
输出：3
解释：12 = 4 + 4 + 4
示例 2：

输入：n = 13
输出：2
解释：13 = 4 + 9

提示：

1 <= n <= 10^4
**************************************************************************************/

/*******************************************************************************************************
题目分析：f[i] 表示最少需要多少个数的平方来表示整数 i。每次可以使用平方求和的条件来制约内层循环的终止条件，可以想见，
这个数必然落在[1,根号n]，我们依次枚举这些数，外层循环当前遍历到i,那么内层的终止条件就是i - j^2≥0.
********************************************************************************************************/

class Solution {
public:
    int numSquares(int n) {
         vector<int> f(n + 1);
         for(int i = 1;i <= n;++i)
         {
             int ori = INT_MAX;
             for(int j = 1; i - j * j >= 0;++j)
             {
                 ori = min(ori, f[i - j * j]);
             }
             f[i] = 1 + ori;
         }
         return f[n];
    }
};
 
