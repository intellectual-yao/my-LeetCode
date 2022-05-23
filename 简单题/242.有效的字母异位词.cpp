// Source : https://leetcode-cn.com/problems/valid-anagram/
// Author：GuoQiang Yao
// Date : 2021-11-5


/******************************************************************************************
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
******************************************************************************************/


/*******************************************************************************************************
题目分析：本题可以直接对两个字符串排序，如果二者相等，直接返回即可，so easy hhhhhh
********************************************************************************************************/
class Solution {
public:
    bool isAnagram(string s, string t) {
        //排序之后比较排序后的序列，如果两者一模一样，则符合题意
        sort(s.begin(), s.end()); 
        sort(t.begin(), t.end());
        return s == t;
    }
};
