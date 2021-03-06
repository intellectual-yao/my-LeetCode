// Source : https://leetcode-cn.com/problems/reverse-only-letters/
// Author : GuoQiang Yao
// Date : 2022-1-9

/**************************************************************************************
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

示例 1：

输入：“ab-cd”
输出：“dc-ba”
示例 2：

输入：“a-bC-dEf-ghIj”
输出：“j-Ih-gfE-dCba”
示例 3：

输入：“Test1ng-Leet=code-Q!”
输出：“Qedo1ct-eeLg=ntse-T!”

提示：

S.length <= 100
33 <= S[i].ASCIIcode <= 122
S 中不包含 \ or "

**************************************************************************************/

/*******************************************************************************************************
题目分析：利用双指针，如果是两侧都是字母就交换位置；如果单侧不是字母就移动相应的index，如果两侧都不是字母，就将两侧的指针都向中间移动。
********************************************************************************************************/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        for(int i = 0,j = s.size() - 1;i < j;)
        {
            //如果这俩都是字母就直接交换位置
            if(isalpha(s[i]) && isalpha(s[j]))
            {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
            //如果左边不是右边是，则下标右移
            else if((!isalpha(s[i])) && isalpha(s[j]))
            {
                ++i;
            }
            //如果左边是右边不是，则下标左移
            else if(isalpha(s[i]) && (!isalpha(s[j])))
            {
                --j;
            }
            //如果两边都是字符，就左移右移同时进行
            else if((!isalpha(s[i])) && (!isalpha(s[j])))
            {
                ++i;
                --j;
            }
        }
        return s;
    }
};
