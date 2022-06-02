// Source : https://leetcode.cn/problems/divide-two-integers/
// Author : GuoQiang Yao
// Date : 2022-6-2
/**************************************************************************************
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333…) = truncate(3) = 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333…) = -2

提示：

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231, 231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
**************************************************************************************/

/*******************************************************************************************************
题目分析：假设 x·a <= b 且 2·x·a > b，如果求 k·a = b 中的k， 那么k一定满足 x <= k < 2x.
这道题也可以利用这种思想，题目要求不能使用乘除法，我们利用倍增加，不断找到 k，然后被除数 dividend-k·divisor，
答案加 k，然后递归直至 dividend < divisor，即不能继续除下去了.
********************************************************************************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 首先处理一些特殊情况
        // 如果被除数为1直接返回除数
        if(divisor == 1)
            return dividend;
        // 最终的结果的正负应该由flag决定
        bool flag = true;
        // 当两个数字有一个为负的时候结果为负
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            flag = false;
        // 如果超出限制就要按照题目进行相应的处理
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        // 因为负数的范围比正数范围大，因此将正数全部变为负数进行计算
        if(dividend > 0)
            dividend = -dividend;
        if(divisor > 0)
            divisor = -divisor;
            
        int ans = 0;
        while(1) 
        {
            int a = dividend, b = divisor, cnt = 1;
            // 现在a,b都是负数
            if (a > b) 
                break;
            // b < a && a < 2 * b的时候进行循环
            while(a - b <= b) 
            {
                cnt += cnt;
                b += b;
            }
            ans += cnt;
            dividend -= b;
        }
        return flag ? ans : -ans;
    }
};  
