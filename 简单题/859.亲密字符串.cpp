// Source : https://leetcode-cn.com/problems/buddy-strings/submissions/
// Author : GuoQiang Yao
// Date : 2022-1-12

/**************************************************************************************
给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。

交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。

例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
 

示例 1：

输入：s = "ab", goal = "ba"
输出：true
解释：你可以交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 相等。
示例 2：

输入：s = "ab", goal = "ab"
输出：false
解释：你只能交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 不相等。
示例 3：

输入：s = "aa", goal = "aa"
输出：true
解释：你可以交换 s[0] = 'a' 和 s[1] = 'a' 生成 "aa"，此时 s 和 goal 相等。
示例 4：

输入：s = "aaaaaaabc", goal = "aaaaaaacb"
输出：true
 

提示：

1 <= s.length, goal.length <= 2 * 104
s 和 goal 由小写英文字母组成


**************************************************************************************/

/*******************************************************************************************************
题目分析:首先统计字符串A，B中字符不匹配的下标;如果不匹配的下标个数不等于 0 或 2 时，不能由A得到B。
如果不匹配的下标个数等于0时，A与B中字符完全相同，还需要A中有重复字符。
最后,如果不匹配的下标个数等于2时，判断交换两对字符后是否匹配。
********************************************************************************************************/

```cpp
// class Solution {
// public:
//     bool buddyStrings(string s, string goal) {
//         vector<int> flag;
//         //如果两者长度不相等那么肯定不符合题意
//         if(s.size() != goal.size())
//             return false;
//         else
//         {
//             for(int i = 0;i < s.size();++i)
//             {
//                 //记录出现不相等的位置
//                 if(s[i] != goal[i])
//                     flag.push_back(i);
//             }
//             //如果出现不相等的地方超过两处则不满足题意
//             if(flag.size() > 2)
//                 return false;
//             //如果两个单词位置都可以对的上
//             else if(flag.size() == 0)
//             {
//                 if(s == goal)
//                     return false;
//                 for(int i = 0;i < s.size() - 1;++i)
//                 {
//                     if(s[i] != s[i + 1])
//                         return false;
//                 }
//             }
//             else
//             {
//                 //否则交换前两个不相等位置上的字符之后判断二者是否相等
//                 swap(s[flag[0]], s[flag[1]]);
//             }
//         }
//         return (s == goal);
//     }
// };

// 统计字符串A，B中字符不匹配的下标。
// 不匹配的下标个数不等于 0 或 2 时，不能由A得到B。
// 不匹配的下标个数等于0时，A与B中字符完全相同，还需要A中有重复字符。
// 不匹配的下标个数等于2时，判断交换两对字符后是否匹配。


class Solution {
public:
    bool buddyStrings(const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        vector<int> index_of_mismatch;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i]) {
                index_of_mismatch.push_back(i);
                if (2 < index_of_mismatch.size()) return false;
            }
        if (index_of_mismatch.size() == 0) {
            return set<char>(a.begin(), a.end()).size() < a.size();
        } else if (index_of_mismatch.size() == 2) {
            return a[index_of_mismatch[0]] == b[index_of_mismatch[1]] &&
                   a[index_of_mismatch[1]] == b[index_of_mismatch[0]];
        }
        return false;
    }
};

```
