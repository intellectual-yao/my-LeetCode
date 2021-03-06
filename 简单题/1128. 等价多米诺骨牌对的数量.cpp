// Source : https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
// Author : GuoQiang Yao
// Date : 2022-4-25

/**************************************************************************************
给你一个由一些多米诺骨牌组成的列表 dominoes。

如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。
形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a == c 且 b == d，或是 a == d 且
b==c。在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。

示例：

输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
输出：1

提示：

1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9
**************************************************************************************/

/*******************************************************************************************************
题目分析： 本题的思路比较巧妙，没有使用双重循环硬解，而是将两个数据按照一定的规则整合起来，
规则就是小数在前大数在后，而这一实现只需要利用三元表达式既可实现，然后将这个两位数存入哈希表，
最后，只需要计算每个两位数的出现次数即可得到正确结果。
********************************************************************************************************/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // 因为是按照两位数进行存储，那么最大数据到100
        vector<int> num(100);
        int res = 0;
        for(auto &it : dominoes)
        {
            //将两个数字转化为一个两位数且大数在前小数在后
            int val = it[0] < it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
            // 首先计算元素出现的次数
            res += num[val];
            // 然后对元素出现的次数进行增加，与上句话的顺序不能相反
            ++num[val];
        }
        return res;
    }
};
