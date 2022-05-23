// Source :https://leetcode-cn.com/problems/reverse-string-ii/
// Date : 2021-11-22

/**************************************************************************************
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
i) 如果剩余字符少于 k 个，则将剩余字符全部反转。
ii) 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例 1：

输入：s = “abcdefg”, k = 2
输出：“bacdfeg”
示例 2：

输入：s = “abcd”, k = 2
输出：“bacd”

提示：

1 <= s.length <= 104
s 仅由小写英文组成
1 <= k <= 104

**************************************************************************************/

/*******************************************************************************************************
题目分析：从本题描述不难发现，如果给定的字符串够长，那么我们每次只翻转前k个字符，但是滑动的步长每次要增加2k个，
也就是每次翻转结束以后，步长要增加2k个。对于第一次来讲，如果本身的字符长度都小于k的话，那么直接翻转全部字符，
否则的话就翻转前k个，然后下一次翻转的起点是现在的位置加上2k
********************************************************************************************************/
class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size(), pos = 0;
        //间隔2*k进行跳跃,pos为每次的起点
        while(pos < len)
        {
            //如果不越界
            if(pos + k < len)
                //翻转前k个
                reverse(s.begin() + pos,s.begin() + pos + k); 
            else
                //剩余字符串不足k的情况
                reverse(s.begin() + pos,s.end());
            //隔2*k
            pos += 2 * k;
        }
        return s;
    }
};
