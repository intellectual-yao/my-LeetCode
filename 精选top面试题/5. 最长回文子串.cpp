// Source : https://leetcode.cn/problems/longest-palindromic-substring/
// Author : GuoQiang Yao
// Date : 2022-5-28

/**************************************************************************************
给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：

输入：s = “babad”
输出：“bab”
解释：“aba” 同样是符合题意的答案。
示例 2：

输入：s = “cbbd”
输出：“bb”

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母组成
**************************************************************************************/

/*******************************************************************************************************
题目分析： 本文主要按照写表格的方法进行,将初始状态进行填写之后对表格中左上角的元素的bool值进行填入,注意的是C++vector二维数组的初始化的方法,需要将表格的长和宽写入.
********************************************************************************************************/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // 如果字符个数小于2的话,就返回当前字符串
        if(n < 2)
            return s;
        int maxlen = 1;
        int begin = 0;

        // 二维数组表示动态规划的表格(DP就是填表)
        // C++ vector初始化需要写上几行几列(n行n列)
        vector<vector<int>> dp(n, vector<int> (n));
        // 初始化对角线元素为true
        for(int i = 0;i < n;++i)
            dp[i][i] = true;
        // 开始填表工作
        for(int L = 2;L <= n;++L)
        {
            for(int i = 0;i < n;++i)
            {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L - 1 + i;
                // 如果右边界越界，就可以退出当前循环
                if(j >= n)
                    break;
                // 如果首尾字符不相等就置当前位置元素为false
                if(s[i] != s[j])
                    dp[i][j] = false;
                else
                {
                    // j - 1 - (i + 1) + 1 < 2
                    if(j - i < 3)
                        dp[i][j] = true;
                    else
                    {
                        // 如果首尾字符均相等,则需要看向里一位的两个字符是否相等
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if(dp[i][j] && j - i + 1 > maxlen)
                {
                    maxlen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};  
