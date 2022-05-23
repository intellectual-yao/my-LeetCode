// Source : https://leetcode-cn.com/problems/maximum-number-of-balloons/
// Author : GuoQiang Yao
// Date : 2022-4-27

/**************************************************************************************
给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 “balloon”（气球）。

字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 “balloon”。

示例 1：

输入：text = “nlaebolko”
输出：1

示例 2：

输入：text = “loonbalxballpoon”
输出：2

示例 3：

输入：text = “leetcode”
输出：0

提示：

1 <= text.length <= 10^4

    1

**************************************************************************************/

/*******************************************************************************************************
题目分析： 开始小编的想法过于复杂,想的是先将两个字符串的每个字符的出现次数进行统计,
然后对balloon中的字符在给定的字符串中进行寻找,后来发现其实没有必要,
甚至都不需要统计balloon的每个字符出现次数,因为这是已知的,因此,
我们只需对给定字符串的字符出现次数按要求进行计算即可.然后对多次出现的字符要进行相应的除法操作,最后返回所有字符中出现次数最小的即为可以组成单词的最多数量.
********************************************************************************************************/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // unordered_map<char, int> cnt_aim;
        unordered_map<char, int> cnt_text;
        // string aim = "balloon";
        // // 计算原单词中每个字符的出现次数
        // for(char c : aim)
        //     ++cnt_aim[c];
        // 计算目标字符串中每个字符的出现次数
        for(char c : text)
            ++cnt_text[c];
// -----------------------------------------------------
        // // 比较两者的每个字符包含的数目
        // for(char c : aim)
        // {
        //     // 如果balloon中的某个字符数大于text中对应的字符数,则退出
        //     if(cnt_aim[c] > cnt_text[c])
        //         return 0;
        // }    
        // // 如果循环结束但是依旧没有退出那么至少可以组成一个balloon
        // // 可以组成balloon的个数就是text字符中符合要求且出现次数最少的那个字符个数
        // // int min_num = 1;
        // // 记录符合要求的元素的出现个数并找出最小值
        // vector<int> cnt;
        // for(char c : aim)
        // {
        //     cnt.push_back(cnt_text[c]);
        // }
        // return *min_element(cnt.begin(), cnt.end());
// ----------------------------------------------------------
        // 压根不用上面那么复杂,直接在text字符串中计算每个符合要求单词的出现次数,返回最小值即可
        return min({cnt_text['b'], cnt_text['a'], cnt_text['l']/2, cnt_text['o']/2, cnt_text['n']});
    }
}; 
