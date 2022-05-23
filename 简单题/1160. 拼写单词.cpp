// Source : https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/
// Author : GuoQiang Yao
// Date : 2022-4-26

/**************************************************************************************
给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写（指拼写词汇表中的一个单词）时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。

示例 1：

输入：words = [“cat”,“bt”,“hat”,“tree”], chars = “atach”
输出：6
解释：
可以形成字符串 “cat” 和 “hat”，所以答案是 3 + 3 = 6。
示例 2：

输入：words = [“hello”,“world”,“leetcode”], chars = “welldonehoneyr”
输出：10
解释：
可以形成字符串 “hello” 和 “world”，所以答案是 5 + 5 = 10。

提示：

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
所有字符串中都仅包含小写英文字母

**************************************************************************************/

/*******************************************************************************************************
题目分析：首先对chars数组中每个字符出现的次数进行统计，然后对words中每个单词的每个字符出现次数进行统计，
如果该单词的某个字符出现次数大于chars中该字符的出现次数则继续下一轮的比较，
如果该单词每个字符出现次数都小于chars中的对应字符的出现次数就将其长度进行统计，最后返回所统计的结果即可。
********************************************************************************************************/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> cnt_char;
        // 计算chars中的每个字符出现的次数
        // vector<char>::iterator it;
        // for(it = chars.begin();it != chars.end();++it)
        for(char it : chars)
            ++cnt_char[it];
        int res = 0;
        for(string word : words)
        {
            // 将每个字符串所含的字符数进行统计
            unordered_map<char, int> cnt_word;
            for(char w : word)
                ++cnt_word[w];
            // 比较每个单词的字符出现次数与chars数组的出现次数
            bool flag = true;
            for(char c : word)
            {
                // 如果单词中的某个字符出现次数比chars中的大，那么直接退出循环
                if(cnt_word[c] > cnt_char[c])
                {
                    // 同时也不需要计数
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                res += word.size();
        }
        return res;
    }
}; 
