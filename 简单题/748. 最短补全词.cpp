// Source : https://leetcode-cn.com/problems/shortest-completing-word/
// Author : GuoQiang Yao
// Date : 2022-3-6

/**************************************************************************************
给你一个字符串 licensePlate 和一个字符串数组 words ，请你找出 words 中的 最短补全词 。

补全词 是一个包含 licensePlate 中所有字母的单词。忽略 licensePlate 中的 数字和空格 。不区分大小写。
如果某个字母在 licensePlate 中出现不止一次，那么该字母在补全词中的出现次数应当一致或者更多。

例如：licensePlate = “aBc 12c”，那么它的补全词应当包含字母 ‘a’、‘b’ （忽略大写）和两个 ‘c’ 。可能的 补全词 有 “abccdef”、“caaacab” 以及 “cbca” 。

请返回 words 中的 最短补全词 。题目数据保证一定存在一个最短补全词。当有多个单词都符合最短补全词的匹配条件时取 words 中 第一个 出现的那个。

示例 1：

输入：licensePlate = “1s3 PSt”, words = [“step”, “steps”, “stripe”, “stepple”]
输出：“steps”
解释：最短补全词应该包括 “s”、“p”、“s”（忽略大小写） 以及 “t”。
“step” 包含 “t”、“p”，但只包含一个 “s”，所以它不符合条件。
“steps” 包含 “t”、“p” 和两个 “s”。
“stripe” 缺一个 “s”。
“stepple” 缺一个 “s”。
因此，“steps” 是唯一一个包含所有字母的单词，也是本例的答案。
示例 2：

输入：licensePlate = “1s3 456”, words = [“looks”, “pest”, “stew”, “show”]
输出：“pest”
解释：licensePlate 只包含字母 “s” 。所有的单词都包含字母 “s” ，其中 “pest”、“stew”、和 “show” 三者最短。答案是 “pest” ，因为它是三个单词中在 words 里最靠前的那个。

提示：

1 <= licensePlate.length <= 7
licensePlate 由数字、大小写字母或空格 ’ ’ 组成
1 <= words.length <= 1000
1 <= words[i].length <= 15
words[i] 由小写英文字母组成

**************************************************************************************/

/*******************************************************************************************************
题目分析：首先对字符进行处理，将字符全部转换为小写并存储起来，然后在单词数组中比较每一个单词与已经存起来的小写字符进行比较，将符合要求的单词进行返回
********************************************************************************************************/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        //找出每个字符的出现次数，利用哈希表进行存储
        unordered_map<char, int> dict;
        for (auto& c : licensePlate)
            //如果字符不是数字并且不是空格就将其转为小写
            if (c != ' ' && !isdigit(c))
                dict[tolower(c)]++;
        string res;
        //计算words中的每个单词的字符出现的频率用来比较
        for (auto& word : words)
        {
            unordered_map<char, int> curFreq;
            for (auto c : word)
                curFreq[c]++;
            //调用函数，当前的字符与给定的进行字符数目的比较
            if (isValid(curFreq, dict))
            {
                if (res.empty() || res.size() > word.size())
                    res = word;
            }
        }
        return res;
    }
    
    /* str1中含有str2中的所有字符 */
    bool isValid(unordered_map<char, int>& dict1, unordered_map<char, int>& dict2)
    {
        for (auto& kvp : dict2)
        {
            if (dict1[kvp.first] < kvp.second)
                return false;
        }
        return true;
    }
};
