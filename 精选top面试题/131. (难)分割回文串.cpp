// Source : https://leetcode.cn/problems/palindrome-partitioning/
// Author : GuoQiang Yao
// Date : 2022-10-17
/**************************************************************************************　
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。

示例 1：

输入：s = “aab”
输出：[[“a”,“a”,“b”],[“aa”,“b”]]
示例 2：

输入：s = “a”
输出：[[“a”]]

提示：

1 <= s.length <= 16
s 仅由小写英文字母组成
**************************************************************************************/

/*******************************************************************************************************
题目分析：对于题目的aab，当处理到第一个字符a时，此时包括字符a在内后面一共有3个字符，
面临3个选项，即可以分割出3个以字符a开头的子字符串，分别为a、aa、aab；对上面的每个子字符串做回文判断，
只取回文的选项，然后进入下一层dfs。
********************************************************************************************************/

class Solution {
public:
    // 结果二维字符串存储
    vector<vector<string>> res;
    // 当前字符串存储
    vector<string> tmp;
    // 判断当前的字符串是否回文
    bool is_reverse(string &s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
    void dfs(string &s, int start)
    {
        if(start == s.length())
        {
            res.push_back(tmp);
            return;
        }
        for(int i = start; i < s.length(); ++i)
        {
            //当前子字符串为回文，保存结果进入下一层dfs
            if(is_reverse(s, start, i) == true)
            {
                tmp.push_back(s.substr(start, i - start + 1));
                // 下一层回溯
                dfs(s, i + 1);
                // 回溯(需要弹出)
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
}; 
