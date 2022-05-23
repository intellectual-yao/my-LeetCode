// Source : https://leetcode-cn.com/problems/valid-palindrome/
// Author ：GuoQiang Yao
// Date : 2021-11-2


/**************************************************************************************
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

**************************************************************************************/



/*******************************************************************************************************
题目分析： 本题使用双指针从头尾开始遍历，直到头指针位置大于尾指针的位置，并且当头尾指针对应的元素不相同的时候退出循环
并返回错误标记即可。另，本代码使用isalnum函数判断当前的字符是否为数字或者字母，如果返回1则说明当前字符为数字或者字母，
将其加入到新的字符串中。
********************************************************************************************************/

class Solution {
public:
    bool isPalindrome(string s) {
        //首先进行字符的筛选，将字符全部放入新字符串中并转为小写
        string new_s;
        for (char ch: s) 
        {
            if (isalnum(ch)) 
            {
                new_s += tolower(ch);
            }
        }
        //len记录新字符串的长度
        int len = new_s.size();
        //定义双指针，从头尾分别向中间遍历，碰到空格就跳过
        for(int i = 0, j = len - 1;i < j;++i, --j)
        {
            if(new_s[i] != new_s[j])
                return false;
        }
        return true;
    }
};
