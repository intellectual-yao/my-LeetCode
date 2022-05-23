// Source : https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/
// Author : GuoQiang Yao
// Date : 2022-3-5

/**************************************************************************************
给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。

示例 1：

输入：deck = [1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
示例 2：

输入：deck = [1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。

提示：

1 <= deck.length <= 104
0 <= deck[i] < 104

**************************************************************************************/

/*******************************************************************************************************
题目分析：将每个元素的出现次数用哈希表存起来，然后对出现次数进行公因数的查找，最终拿到的公因数大于2就是满足题意。
********************************************************************************************************/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        //采用哈希表存放元素及其对应的出现次数
        unordered_map<int, int> map_card;
        //记录每个元素的出现次数
        vector<int> num_count;

        for(auto n : deck)
            map_card[n] += 1;
        for(auto n : map_card)
            num_count.push_back(n.second);

        //排序数组便于查找
        sort(num_count.begin(), num_count.end());
        //题目要求可选的n需要大于等于2，因此循环的起始条件是i = 2
        for(int i = 2;i <= num_count[0];++i)
        {
            int flag = 1;
            for(int j = 0;j < num_count.size();++j)
            {
                //用每一个次数除以公因数，找到是否存在可行的分组
                if(num_count[j] % i != 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
                return true;
        }
        return false;
    }
};
