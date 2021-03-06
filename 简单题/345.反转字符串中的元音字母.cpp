// Source : https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
// Author ：GuoQiang Yao
// Date : 2021-11-7

//简单题我依旧重拳出击
/******************************************************************************************
题目描述：给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。

示例 1：

输入：s = "hello"
输出："holle"
示例 2：

输入：s = "leetcode"
输出："leotcede"
 

提示：

1 <= s.length <= 3 * 105
s 由 可打印的 ASCII 字符组成

******************************************************************************************/

/*******************************************************************************************************
题目分析：本题可以直接对两个字符串利用双指针从两侧向中间遍历，需要判断当前字符是否属于元音字符，
若是，就交换二者对应的字符，否则就继续向后查找，但是本题较好的做法是将大小写元音字符均放入一个字符串中，每次就判断当前字符是否在元音字符串中。
********************************************************************************************************/

class Solution {
public:
    string reverseVowels(string s) 
    {        
        //直接定义字符串，然后每次看当前字符是否在该字符串中
        string t = "aeiouAEIOU";
        for(int i = 0, j = s.size() - 1;i < j;)
        {
            while(t.find(s[i]) == -1 && i < j)
                i++;
            while(t.find(s[j]) == -1 && i < j)
                j--;
            //交换以后要将i,j分别移动，否则会报超时
            if(i<j)
                swap(s[i++],s[j--]);
        }
        return s;
    }
};
