// Source : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
// Author ：GuoQiang Yao
// Date : 2021-09-25


/******************************************************************************************
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

******************************************************************************************/


/*******************************************************************************************************

题目分析：本题重点在于需要获得最大利润，而不是仅仅通过一次判断就看能不能获利（小编最初就是想着如果一次判断不成功，就直接返回0）
后来仔细读题以后发现需要得到的是最大利润，也就是如果当前情况不够好，你应该去考虑下一次的情况，于是想到了暴力法：
也就是每次找出当前元素与其后元素的最大差值，然后将最大差值返回，但是由于时间复杂度的问题，超时了，所以就只能再换套路，
最终利用循环，遍历每个元素，进行两个计算，首先是比较最小成本与当前价格的大小，选小的作为最小成本。
然后，计算当前的大利润与当前价格数组的元素与最小成本的最大值，记为最大利润，然后在比较结束以后将最大利润进行返回。

********************************************************************************************************/
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        // //计算容器的长度
        // //给定一个res初始值，用于与利润
        // int res = 0, len = prices.size();
        // for(int i = 0;i < len;++i)
        //     for(int j = i + 1;j < len;++j)
        //          res = max(res, prices[j] - prices[i]);
        // return res;
        //上述代码尝试了双层循环结束问题，然而超时了
        
        //最终采用了一个不错的思路：查找到当天为止最大的收益和最小的购买价格
        //此处将min_cost置为正无穷，方便后面的最大利润以及最小成本计算
        int min_cost = int(1e9), max_pro = 0, len = prices.size();;
        if(len == 1)
             return 0;
        //遍历数据查找最大利润并返回
        for(auto price : prices)
        {
            //找出最小成本与当前价格的最小值，用来更新最小成本
            min_cost = min(min_cost, price);
            //找出最大利润与当前价格减去最小成本的最大值
            max_pro = max(max_pro, price - min_cost);
        }
        return max_pro;
        // 下面代码是最原始的想法

        // //先计算出数组长度
        // // int len = sizeof(prices) / sizeof(prices[0]);
        // int len = prices.size();
        // if(len == 1)
        //     return 0;
        // else
        // {
        //     //求出容器中最小值元素
        //     vector<int>::iterator the_min_ele = min_element(prices.begin(), prices.end());
        //     //如果最小值在最后位置上，判断还有没有可能获得利润，而不是直接返回0
        //     if(*the_min_ele == prices[len - 1])
        //     {
        //         //除去最后一个元素，看剩下的元素还能不能获得最大利润
        //         int new_len = len - 1;
        //         //如果除去最后一个元素就剩一个元素，直接返回0
        //         if(new_len == 1)
        //             return 0;
        //         else
        //         {
        //             //求出新容器中最小值元素
        //             vector<int>::iterator new_min_ele = min_element(prices.begin(), prices.end() - 1);
        //             //找出新容器中最小值元素的下标
        //             vector<int>::iterator min_loc = find(prices.begin(), prices.end(), *new_min_ele);
        //             //找出新容器中最小值之后的最大值
        //             vector<int>::iterator new_rear_max = max_element(min_loc, prices.end() - 1);
        //                 return *new_rear_max - *new_min_ele;
        //         } 
        //     }
        //     else
        //     //如果最小值不在最后位置上，可以直接返回利润
        //     {
        //         //求出新容器中最小值元素
        //         vector<int>::iterator the_min_ele = min_element(prices.begin(), prices.end());
        //         //找出最小值元素的下标
        //         vector<int>::iterator min_loc = find(prices.begin(), prices.end(), *the_min_ele);
        //         //找出最小值之后的数组中的最大值
        //         vector<int>::iterator rear_max = max_element(min_loc, prices.end());
        //             return *rear_max - *the_min_ele;
        //     }
        // }
    }
};

