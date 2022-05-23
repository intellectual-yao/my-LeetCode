// Source : https://leetcode-cn.com/problems/is-subsequence/
// Author : GuoQiang Yao
// Date : 2021-11-11

/**************************************************************************************
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
进阶：如果有大量输入的 S，称作 S1, S2, … , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：

特别感谢 @pbrother 添加此问题并且创建所有测试用例。

示例 1：

输入：s = “abc”, t = “ahbgdc”
输出：true
示例 2：

输入：s = “axc”, t = “ahbgdc”
输出：false

提示：

0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成。
**************************************************************************************/

/*******************************************************************************************************
题目分析： 注释掉的是小编最初的想法，从s的第一个字符开始在t中查找字符的Index，并将index加入到index数组中，
最后判断Index数组是否有序，若有序则说明满足题意，反之返回false即可。
然，查看了官方解法以后发现官方解法更直接简单，直接判断两个对应位置的字符是否相等，如果不相等，
就把t的index向后移动看能否找到，如果找到，就将s中的index向后移动，最后如果s的元素不全被找到，则说明不符合要求，注意的是，利用本方法，就巧妙地避免了在t中找到上一个元素之前位置地元素。
********************************************************************************************************/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
};
// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         //将s中在t中的元素下标放入该数组
//         vector<int> index;
//         vector<int> sort_index;
//         // int _index = 0;
//         for(int i = 0;i < s.size();++i)
//         {
//             int _index = t.find(s[i]);
//             //如果找不到元素，直接返回错误
//             if(_index > t.size())
//                 return false;
//             else
//             {
//                 //t中对应的元素改为0
//                 t[_index] = '0';
//                 index.push_back(_index);
//                 i = _index;
//             }
//         }
//         //对index数组排序，如果排序前后二者相同则说明有序
//         for(int i = 0;i < index.size();++i)
//         {
//             sort_index.push_back(index[i]);
//         }
//         // sort_index = index;
//         //对index数组排序，如果排序前后二者相同则说明有序
//         sort(index.begin(), index.end());
//         if(sort_index == index)
//             return true;
//         else
//             return false;
//     }
// };
