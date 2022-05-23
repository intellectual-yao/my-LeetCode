// Source : https://leetcode.cn/problems/add-digits/
// Author : GuoQiang Yao
// Date : 2022-5-11

/**************************************************************************************
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。

示例 1:

输入: num = 38
输出: 2
解释: 各位相加的过程为：
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
由于 2 是一位数，所以返回 2。
示例 1:

输入: num = 0
输出: 0

提示：

0 <= num <= 231 - 1

**************************************************************************************/

/*******************************************************************************************************
题目分析： 见代码即可。
********************************************************************************************************/

class Solution {
public:
    int addDigits(int num) {
        // 当每次所求和的数字大于10的时候进行循环
        while (num >= 10) {
            int sum = 0;
            // 进行每个数位上的数字的求和
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            // 求和之后将数字传递给下一次要进行求和的变量
            num = sum;
        }
        return num;
    }
}; 
