// Source : https://leetcode-cn.com/problems/find-common-characters/
// Author : GuoQiang Yao
// Date : 2022-1-25

/**************************************************************************************
给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。

示例 1：

输入：words = [“bella”,“label”,“roller”]
输出：[“e”,“l”,“l”]
示例 2：

输入：words = [“cool”,“lock”,“cook”]
输出：[“c”,“o”]

提示：

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] 由小写英文字母组成

**************************************************************************************/

/*******************************************************************************************************
题目分析：首先对每个单词的字符数目进行处理，计算出每个单词的字母出现的次数，用下标进行记录，最后将下标在通过ascii码的方式转化成对应的单词。
********************************************************************************************************/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minfreq(26, INT_MAX);
        vector<int> freq(26);
        for (const string& word: words) 
        {
            //因为涉及到自增的问题，因此这里必须给数组填充0
            fill(freq.begin(), freq.end(), 0);
            //将每个单词的出现次数放入数组中,下标从0--25
            for (char ch: word) 
                ++freq[ch - 'a'];
            for (int i = 0; i < 26; ++i) 
                //从index入手，将最小的赋值
                minfreq[i] = min(minfreq[i], freq[i]);
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minfreq[i]; ++j) {
                //如果一个元素出现多次，则需要把这个元素都添加进结果数组，注意：从Index转换到字符的方式
                ans.emplace_back(1, i + 'a');
            }
        }
        return ans;
    }
};
