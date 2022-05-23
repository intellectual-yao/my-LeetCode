// Source : https://leetcode-cn.com/problems/verifying-an-alien-dictionary/submissions/
// Author : GuoQiang Yao
// Date : 2022-1-17

/**************************************************************************************
某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

示例 1：

输入：words = [“hello”,“leetcode”], order = “hlabcdefgijkmnopqrstuvwxyz”
输出：true
解释：在该语言的字母表中，‘h’ 位于 ‘l’ 之前，所以单词序列是按字典序排列的。
示例 2：

输入：words = [“word”,“world”,“row”], order = “worldabcefghijkmnpqstuvxyz”
输出：false
解释：在该语言的字母表中，‘d’ 位于 ‘l’ 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
示例 3：

输入：words = [“apple”,“app”], order = “abcdefghijklmnopqrstuvwxyz”
输出：false
解释：当前三个字符 “app” 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 “apple” > “app”，因为 ‘l’ > ‘∅’，其中 ‘∅’ 是空白字符，定义为比任何其他字符都小（更多信息）。

提示：

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
在 words[i] 和 order 中的所有字符都是英文小写字母。

**************************************************************************************/

/*******************************************************************************************************
题目分析：按照题目，直接比较每一个字符串的每一个字符的大小即可，大小的顺序就是其在order中的位置（索引）。
********************************************************************************************************/

// class Solution {
// public:
//     bool isAlienSorted(vector<string>& words, string order) {
//         int len = words.size();
//         for(int i = 0;i < len - 1;++i)
//         {
//             if(words[i].size() > words[i + 1].size())
//                 return false;
//         }
        
//     }
// };

class Solution {
public:
    //定义字典序的比较方式
    bool less(string& a, string& b, string& order) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; i++) {
            if (order.find(a[i]) < order.find(b[i])) return true;
            else if (order.find(a[i]) > order.find(b[i])) return false;
        }
        if (len == a.size()) return true;
        else return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        //直接遍历words,若不符合升序就直接报false，遍历完发现为升序，说明该单词集为true
        for (int i = 0; i < words.size() - 1; i++) {
            if (!less(words[i], words[i + 1], order)) return false;
        }
        return true;
    }
};
