// Source : https://leetcode-cn.com/problems/uncommon-words-from-two-sentences/
// Author : GuoQiang Yao
// Date : 2022-1-13

/**************************************************************************************
句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。

如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现 ，那么这个单词就是 不常见的 。

给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按 任意顺序 组织。

示例 1：

输入：s1 = “this apple is sweet”, s2 = “this apple is sour”
输出：[“sweet”,“sour”]
示例 2：

输入：s1 = “apple apple”, s2 = “banana”
输出：[“banana”]

提示：

1 <= s1.length, s2.length <= 200
s1 和 s2 由小写英文字母和空格组成
s1 和 s2 都不含前导或尾随空格
s1 和 s2 中的所有单词间均由单个空格分隔

**************************************************************************************/

/*******************************************************************************************************
题目分析：将两个字符串合并，找出只出现一次的单词即可，为了方便，小编使用了字符输入流处理单词的个数问题
********************************************************************************************************/

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> mymap;
        //将两个字符串拼在一起
        A = A + " " + B;
        //istringstream对象可以绑定一行字符串，然后以空格为分隔符把该行分隔开来。
        istringstream words(A);
        string w;
        vector<string> ans;
        //将每一个单词装入哈希表中，并记录每个单词出现的次数
        while (words >> w) 
            ++mymap[w];
        //查看哈希表中每个单词出现的次数，如果只出现一次则可以加入到结果数组中
        for (auto m : mymap)
            if (m.second == 1) 
                ans.push_back(m.first);
        return ans;
    }
};
