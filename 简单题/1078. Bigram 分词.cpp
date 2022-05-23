// Source : https://leetcode-cn.com/problems/occurrences-after-bigram/submissions/
// Author : GuoQiang Yao
// Date : 2022-1-28

/**************************************************************************************
给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 “first second third” 形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。

对于每种这样的情况，将第三个词 “third” 添加到答案中，并返回答案。

示例 1：

输入：text = “alice is a good girl she is a good student”, first = “a”, second = “good”
输出：[“girl”,“student”]
示例 2：

输入：text = “we will we will rock you”, first = “we”, second = “will”
输出：[“we”,“rock”]

提示：

1 <= text.length <= 1000
text 由小写英文字母和空格组成
text 中的所有单词之间都由 单个空格字符 分隔
1 <= first.length, second.length <= 10
first 和 second 由小写英文字母组成

**************************************************************************************/

/*******************************************************************************************************
题目分析：本题很像之前小编刷过的一道，使用字符流进行解答的问题，直接将按照空格分隔好的单词一次放入一个新的字符数组中，
然后按照题目进行判断，将符合题意得单词放入结果数组中即可。
********************************************************************************************************/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        //以空格分隔整个字符串
        stringstream ss(text);
        vector<string> words, ans;
        string word;
        //字符串写入新的字符数组中，且没有空格的影响
        while(ss>>word) 
            words.emplace_back(word);
        //如果前两个满足题意，则输出其后的单词
        for(int i = 0; i < words.size()-2; i++){
            if(words[i] == first && words[i+1] == second){
                // ans.push_back(words[i+2]);
                ans.emplace_back(words[i+2]);
            }
        }
        return ans;
    }
}; 
