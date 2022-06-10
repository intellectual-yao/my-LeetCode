// Source : https://leetcode.cn/problems/group-anagrams/
// Author : GuoQiang Yao
// Date : 2022-6-10
/**************************************************************************************
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

示例 1:

输入: strs = [“eat”, “tea”, “tan”, “ate”, “nat”, “bat”]
输出: [[“bat”],[“nat”,“tan”],[“ate”,“eat”,“tea”]]
示例 2:

输入: strs = [“”]
输出: [[“”]]
示例 3:

输入: strs = [“a”]
输出: [[“a”]]

提示：

1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
**************************************************************************************/

/*******************************************************************************************************
题目分析：首先想到的就是将所有字符排序，然后将排序后的字符与排序前的字符存入哈希表中，
如果排序后的字符一样的话就在尾部继续添加排序前的元素，然后遍历哈希表，将每个键（排序后的字符串）对应的值（原始的字符串）存入二维数组中。
********************************************************************************************************/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 将原字符与排序后的字符作为映射存入哈希表
        unordered_map<string, vector<string>> hashmap;
        for(string & str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            // 只要排序后一样，就将原来的字符加入当前键对应的值
            hashmap[tmp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = hashmap.begin(); it != hashmap.end(); ++it)
        {
            ans.push_back(it -> second);
        }
        return ans;
    }
}; 
