// Source : https://leetcode-cn.com/problems/goat-latin/
// Author : GuoQiang Yao
// Date : 2022-1-10

/**************************************************************************************
给定一个由空格分割单词的句子 S。每个单词只包含大写或小写字母。我们要将句子转换为 “Goat Latin”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。

山羊拉丁文的规则如下：

如果单词以元音开头（a, e, i, o, u），在单词后添加"ma"。
例如，单词"apple"变为"applema"。

如果单词以辅音字母开头（即非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
例如，单词"goat"变为"oatgma"。

根据单词在句子中的索引，在单词最后添加与索引相同数量的字母’a’，索引从1开始。
例如，在第一个单词后添加"a"，在第二个单词后添加"aa"，以此类推。
返回将 S 转换为山羊拉丁文后的句子。

示例 1:

输入: “I speak Goat Latin”
输出: “Imaa peaksmaaa oatGmaaaa atinLmaaaaa”
示例 2:

输入: “The quick brown fox jumped over the lazy dog”
输出: “heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa”
说明:

S 中仅包含大小写字母和空格。单词间有且仅有一个空格。
1 <= S.length <= 150。

**************************************************************************************/

/*******************************************************************************************************
题目分析：按照题目一步一步处理，需要注意的是如何处理每个单词
********************************************************************************************************/

class Solution {
public:
    string toGoatLatin(string S) {
        //建立查询表
        string tmpStr = "aeiouAEIOU";
        int i = 0, count = 0;
        string ans = "";
        while (i < S.size()) 
        {
            int j = i;
            //只要当前字符不是空格也不超出范围
            while (isalpha(S[j]) && (j < S.size()))
                j++;
            count += 1;
            //只要首字符在查询表中被找到得话
            if (tmpStr.find(S[i]) != string::npos) 
                //在单词末尾添加ma,注意这里用j-1而不是j,j是在空格的位置上
                ans = ans + S.substr(i, j-i) + "ma";
            else 
                //如果是辅音字母开头的话
                ans = ans + S.substr(i+1, j-i-1) + S[i] + "ma";
            //添加相应数量的a
            for (int i = 0; i < count; i++)
                ans += "a";
            //为了方便在最后一个位置添加空格
            ans.push_back(' ');
            i = j + 1;
        }
        //最后一个位置是自己添加的空格故需要剔除
        ans = ans.substr(0, ans.size()-1);
        return ans;
    }
};
