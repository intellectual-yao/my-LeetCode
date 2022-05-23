// Source : https://leetcode-cn.com/problems/valid-palindrome-ii/
// Author : GuoQiang Yao
// Date : 2021-11-27

/**************************************************************************************
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

 

示例 1:

输入: s = "aba"
输出: true
示例 2:

输入: s = "abca"
输出: true
解释: 你可以删除c字符。
示例 3:

输入: s = "abc"
输出: false
 

提示:

1 <= s.length <= 105
s 由小写英文字母组成


**************************************************************************************/

/*******************************************************************************************************
题目分析： 回文字符相信大家都可以比较容易的写出代码，那，相较于本题，只是当字符出现了不是回文的时候，
需要将首尾指针根据情况移动一位，然后在利用首尾指针进行判断是否回文即可，如果回文的代码直接可以解决问题，
那就说明不需要进行删除操作，否则需要在不是回文的时候删除一个字符，在进行判断。
********************************************************************************************************/


// class Solution {
// public:
//     bool validPalindrome(string s) {
//         int i = 0,j = s.size() - 1;
//         //如果有奇数个字符的话
//         if(s.size() % 2 == 1)
//         {
//             for(;i < j;++i, --j)
//             {
//                 if(s[i] != s[j])
//                     return false;
//             }
//             return true;
//         }
//         //如果有偶数个字符的话
//         else
//         {
//             //中间两个字符可以不用比较
//             for(;j - i > 1;++i, --j)
//             {
//                 if(s[i] != s[j])
//                     return false;
//             }
//             return true;
//         }
//     }
// };

class Solution {
public:
    bool validPalindrome(string s) {
        int head = 0, tail = s.size()-1;
        while(head < tail) //正常双指针判断回文字符串
        {
            if(s[head] == s[tail])
            {
                ++head;
                --tail;
            }
            else
                break; //从分歧点退出
        }
        if(head >= tail) //如果是正常退出
            return true;

        //情况1:因为左侧字符导致不是回文，则head指针右移
        int new_head = head + 1, new_tail = tail;
        int flag1 = true, flag2 = true;
        while(new_head < new_tail)
        {
            if(s[new_head] == s[new_tail])
            {
                ++new_head;
                --new_tail;
            }
            else
            {
                flag1 = false;
                break;
            }
        }

        //情况2：因为右侧字符导致不是回文，则tail指针左移
        new_head = head;
        new_tail = tail - 1;
        while(new_head < new_tail)
        {
            if(s[new_head] == s[new_tail])
            {
                ++new_head;
                --new_tail;
            }
            else
            {
                flag2 = false;
                break;
            }   
        }

        //由于对两种情况进行遍历，所以只要有一种能满足回文，那就可以！
        return flag1 || flag2;
    }
};
