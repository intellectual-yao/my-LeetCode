// Source : https://leetcode.cn/problems/word-break/
// Author : GuoQiang Yao
// Date : 2022-10-23
/**************************************************************************************　
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例 1：

输入: s = “leetcode”, wordDict = [“leet”, “code”]
输出: true
解释: 返回 true 因为 “leetcode” 可以由 “leet” 和 “code” 拼接成。
示例 2：

输入: s = “applepenapple”, wordDict = [“apple”, “pen”]
输出: true
解释: 返回 true 因为 “applepenapple” 可以由 “apple” “pen” “apple” 拼接成。
注意，你可以重复使用字典中的单词。
示例 3：

输入: s = “catsandog”, wordDict = [“cats”, “dog”, “sand”, “and”, “cat”]
输出: false

提示：

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s 和 wordDict[i] 仅有小写英文字母组成
wordDict 中的所有字符串 互不相同
**************************************************************************************/

/*******************************************************************************************************
题目分析：从原字符串中开始查找，挨个字符比对worddict中的每个单词，看是否可以匹配，如果可以匹配到原字符串中的所有字符的话就返回true。
********************************************************************************************************/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        // 挨个单词进行查找
        for(int i = 1;i <= s.size();++i)
        {
            for(auto &word : wordDict)
            {
                int tmp_size = word.size();
                if(i - tmp_size >= 0 && s.substr(i - tmp_size, tmp_size) == word)
                    dp[i] = dp[i] || dp[i - tmp_size];
            }
        }
        return dp[s.size()];
    }
};
