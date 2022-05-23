// Source : https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/
// Author : GuoQiang Yao
// Date : 2021-11-25

/**************************************************************************************
假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。

示例 1:

输入:
[“Shogun”, “Tapioca Express”, “Burger King”, “KFC”]
[“Piatti”, “The Grill at Torrey Pines”, “Hungry Hunter Steakhouse”, “Shogun”]
输出: [“Shogun”]
解释: 他们唯一共同喜爱的餐厅是“Shogun”。
示例 2:

输入:
[“Shogun”, “Tapioca Express”, “Burger King”, “KFC”]
[“KFC”, “Shogun”, “Burger King”]
输出: [“Shogun”]
解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
提示:

两个列表的长度范围都在 [1, 1000]内。
两个列表中的字符串的长度将在[1，30]的范围内。
下标从0开始，到列表的长度减1。
两个列表都没有重复的元素。

**************************************************************************************/

/*******************************************************************************************************
题目分析： 本题思路还是较容易想出，即用第一个列表去建立哈希表，然后遍历第二个列表，查找每一个在哈希表的元素，
如果二者相同，则记录二者位置的下标和，然后继续向后遍历，如果又碰到相同的元素的话，继续计算二者的下标和，如果小于的话，就更新原有的下标。
********************************************************************************************************/

// 哈希的解法

// 单次遍历 list1 去构建一个字符串到索引的映射
// 单次遍历 list2 去查找字符串是否存在，构建索引和到字符串的映射sum2strs 并记录最小的索引和，
// 基于最小索引和获取 sums2strs[minSum]

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        //将list1中的元素放进第一个哈希表中
        unordered_map<string, int> str1ind;
        for (int i = 0; i < list1.size(); ++i)
        {
            str1ind[list1[i]] = i;
        }

        unordered_map<int, vector<string>> sum2strs;
        int minSum = INT_MAX;
        //list2中的元素依次在哈希表中进行查找
        for (int i = 0; i < list2.size(); ++i)
        {
            //当查找到相同的元素了，计算下标和
            if (str1ind.find(list2[i]) != str1ind.end())
            {
                int curSum = i + str1ind[list2[i]];
                //如果下表和小于最小的下标和，就将对应的元素加入到返回的vector中
                if (curSum <= minSum)
                {
                    minSum = curSum;
                    sum2strs[minSum].push_back(list2[i]);
                }
            }
        }
        return sum2strs[minSum];
    }
};
