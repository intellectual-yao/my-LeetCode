// Source : https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/
// Author : GuoQiang Yao
// Date : 2022-1-27

/**************************************************************************************
对于字符串 S 和 T，只有在 S = T + … + T（T 自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

示例 1：

输入：str1 = “ABCABC”, str2 = “ABC”
输出：“ABC”
示例 2：

输入：str1 = “ABABAB”, str2 = “ABAB”
输出：“AB”
示例 3：

输入：str1 = “LEET”, str2 = “CODE”
输出：""

提示：

1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] 和 str2[i] 为大写英文字母

**************************************************************************************/

/*******************************************************************************************************
题目分析：假设两个串A, B满足有该题要求的最大公因子M，那么A = t1M, B=t2M，（A+B)=(B+A)=(t1 + t2)*M。先判断A+B 是否等于 B+A，
不相等，则没有公因子。相等的话，就找两者长度的最大公因子。并返回字符串从0到公因子的长度即可
********************************************************************************************************/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        //如果两个字符串反转相加不相等的时候说明不存在公因子
        if((str1 + str2) != (str2 + str1))    
            return "";
        int res = maxPublicDig(str1.size(), str2.size());
        //从初始点到最大公因子的点的子序列
        return str1.substr(0, res);
    }
    //巧妙地转换，求解出所求字符串的index
    int maxPublicDig(int a, int b)
    {
        while(a != 0 && b != 0)
        {
            a = a % b;
            if(a == 0)
                break;
            swap(a,b);
        }
        return b;
    }
};
