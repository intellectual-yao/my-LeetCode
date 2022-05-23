// Source : https://leetcode-cn.com/problems/jewels-and-stones/
// Author：GuoQiang Yao
// Date : 2021-12-30

/******************************************************************************************
给你一个字符串 jewels 代表石头中宝石的类型，另有一个字符串 stones 代表你拥有的石头。 stones 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

字母区分大小写，因此 “a” 和 “A” 是不同类型的石头。

示例 1：

输入：jewels = “aA”, stones = “aAAbbbb”
输出：3
示例 2：

输入：jewels = “z”, stones = “ZZ”
输出：0

提示：

1 <= jewels.length, stones.length <= 50
jewels 和 stones 仅由英文字母组成
******************************************************************************************/

/******************************************************************************************
题目分析：逐个对比字符即可
******************************************************************************************/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        //定义计数器
        int count = 0;
        int jewels_len = jewels.size(), stones_len = stones.size();
        //逐个对比字符是否相等即可
        for(int i = 0;i < stones_len; ++i)
        {
            for(int j = 0;j < jewels_len;++j)
            {
                if(jewels[j] == stones[i])
                    count++;
            }
        }
        return count;
    }
};
