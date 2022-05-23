// Source : https://leetcode-cn.com/problems/ransom-note/submissions/
// Author：GuoQiang Yao
// Date : 2021-11-8

简单题我还是重拳出击
/******************************************************************************************
题目描述：
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true


******************************************************************************************/

/*******************************************************************************************************
题目分析：本题只需要在magazine中查找救赎信中的每个字符是否存在，如果存在，则将对应的字符给出一定的标记;
本题采用的是直接修改magazine中的该字符，然后在进行遍历，如果最终有一个字符没有找到则直接返回false，如果每个字符都可以在magazine中找到就返回true。
********************************************************************************************************/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(int i = 0;i < ransomNote.size();++i)
        {
            //首先找到该字符在杂志中的位置，然后对杂志中的字符给一个标记
            int index = magazine.find(ransomNote[i]);
            if(index != -1)
                magazine[index] = '1';
            else
                return false;
        }
        return true;
    }
};
