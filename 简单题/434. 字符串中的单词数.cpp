// Source : https://leetcode-cn.com/problems/number-of-segments-in-a-string/
// Author : GuoQiang Yao
// Date : 2021-11-15

/**************************************************************************************
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: “Hello, my name is John”
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 “Hello,” 算作 1 个单词。

**************************************************************************************/

/*******************************************************************************************************
题目分析：当一个字符为空格且其下一个字符不为空格，则计数器可以自增。
********************************************************************************************************/

// 此类统计问题，因为牵扯到最后一个字符的问题，所以笔者最初使用的
// 判断方法（判断一个元素与其后面的元素的关系）的方法并不适合，
// 应该采用后续的改进方法，即使用某个元素之前的哪个元素与当前元素
// 的关系，来看是否对计数器进行自增运算


// class Solution {
// public:
//     int countSegments(string s) {
//         int count = 0;
//         if(s.size() == 0)
//             return 0;
//         for(int i = 0;i < s.size() - 1;++i)
//         {
//             //如果是空格，则计数器自增
//             if(s[i] == ' ' && s[i + 1] != ' ')
//                 ++count;
//         }
//         if(s[s.size() - 1] != ' ')
//             return count + 1;
//         else 
//             return count;
//     }
// };


class Solution {
public:
    int countSegments(string s) {
        int segmentCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                segmentCount++;
            }
        }
        return segmentCount;
    }
};
