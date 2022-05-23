// Source : https://leetcode-cn.com/problems/isomorphic-strings/
// Author：GuoQiang Yao
// Date : 2021-11-3


/******************************************************************************************
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

******************************************************************************************/


/*******************************************************************************************************
题目分析：本题意思就是当前字符串的字符，要与另一个字符串的字符产生映射，同样地，另一个字符串地每一个元素也要与当前字符串地字符产生对应地映射，
每一个字符只能映射到一个字符，不可以出现一个字符映射到多个字符的情况。

********************************************************************************************************/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //建立两个互相的哈希映射，看是否满足双向映射
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int len = s.length();
        for (int i = 0; i < len; ++i) 
        {
            char x = s[i], y = t[i];
            //首先查找元素是否存在，然后比较对应位置是否满足映射
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) 
            {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};
