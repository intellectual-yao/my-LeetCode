// Source : https://leetcode-cn.com/problems/word-pattern/submissions/
// Author : GuoQiang Yao
// Date : 2022-3-4

/**************************************************************************************
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = “abba”, str = “dog cat cat dog”
输出: true
示例 2:

输入:pattern = “abba”, str = “dog cat cat fish”
输出: false
示例 3:

输入: pattern = “aaaa”, str = “dog cat cat dog”
输出: false

提示:

1 <= pattern.length <= 300
pattern 只包含小写英文字母
1 <= s.length <= 3000
s 只包含小写英文字母和 ’ ’
s 不包含 任何前导或尾随对空格
s 中每个单词都被 单个空格 分隔

**************************************************************************************/

/*******************************************************************************************************
题目分析：此类问题需要注意的就是要先进行判断，然后进行赋值，如果先进行了赋值，
那么每次循环都会将上一轮的赋值刷新掉，此类问题使用字符流比较好解决，用字符流以及哈希函数，
将字符与单词的双向映射存起来，然后判断是否相等。
********************************************************************************************************/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c2s; // 字符映射到单词
        unordered_map<string, char> s2c; // 单词映射到字符
        stringstream ss(s); // 字符串流把单词放入用来进行判断
        string t;
        for(auto c: pattern) {
            ss >> t; // 读入非空单词
            //这里要注意的是，赋值操作应该在下面而不是上面
            //如果在上面赋值的话会导致原有的值被刷新导致判断出错
            // c2s[c] = t; // c字符映射到t单词
            // s2c[t] = c; // t单词映射到c字符
            if(c2s.count(c) && c2s[c] != t) 
                return false; // c字符在pattern中已出现，但对应单词不一致
            if(s2c.count(t) && s2c[t] != c) 
                return false; // t单词在s中已出现，但对应字符不一致
            c2s[c] = t; // c字符映射到t单词
            s2c[t] = c; // t单词映射到c字符
        }
        if(ss >> t) // s单词数超过pattern字符数
            return false;
        return true;
    }
};
