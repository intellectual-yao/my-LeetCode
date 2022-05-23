// Source : https://leetcode-cn.com/problems/length-of-last-word/
// Author：GuoQiang Yao
// Date : 2021-11-1


/******************************************************************************************
Given a string s consisting of some words separated by some number of spaces,
return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

******************************************************************************************/


/*******************************************************************************************************
题目分析：本题只需要从最后面开始向前遍历，首先考虑最后一个单词之后有空格的情况，
将索引前移到最后一个单词的位置，然后当没有碰到空格的时候让计数器自增，最后将计数器返回即可。
********************************************************************************************************/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int s_len = s.size() - 1;
        int count = 0; 

        //当最后一个字符后有空格的时候，游标前移
        while(s[s_len] == ' ')
        {
            s_len--;

        }
        //这里必须首先判断索引是否越界然后才能看对应的元素
        while(s_len >= 0 &&s[s_len] != ' ')
        {
            s_len--;
            count++;
        }
            
        return count;
    }
}; 
