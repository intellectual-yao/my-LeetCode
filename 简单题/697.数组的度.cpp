// Source : https://leetcode-cn.com/problems/degree-of-an-array/
// Author : GuoQiang Yao
// Date : 2022-2-19

/**************************************************************************************
给定一个非空且只包含非负数的整数数组 nums，数组的 度 的定义是指数组里任一元素出现频数的最大值。

你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

示例 1：

输入：nums = [1,2,2,3,1]
输出：2
解释：
输入数组的度是 2 ，因为元素 1 和 2 的出现频数最大，均为 2 。
连续子数组里面拥有相同度的有如下所示：
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组 [2, 2] 的长度为 2 ，所以返回 2 。
示例 2：

输入：nums = [1,2,2,3,1,4,2]
输出：6
解释：
数组的度是 3 ，因为元素 2 重复出现 3 次。
所以 [2,2,3,1,4,2] 是最短子数组，因此返回 6 。

提示：

nums.length 在 1 到 50,000 范围内。
nums[i] 是一个在 0 到 49,999 范围内的整数。

**************************************************************************************/

/*******************************************************************************************************
题目分析：本题需要注意的是：小编开始很单纯的想到，直接排序找到与数组的度相同的数字，然后从左右两侧开始遍历，
找到了两个对应的数据之后直接相减下标即可；然而后来发现，如果出现了多组与数组的度相同的数据，那么本方法就不奏效了，
因此还是想到应该用哈希表来计算每组数据的下标然后将计算结果保存，最后进行他们之间的下标比较，返回较小的那个即可。
********************************************************************************************************/

using namespace std;
class Solution 
{
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int, int> digit_cnt;            //统计每个数字的频率
        unordered_map<int, int> first_appear_index;   //记录数字第一次出现的index
        unordered_map<int, int> last_appear_index;    //记录数字最后一次出现的index
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            digit_cnt[num] ++;
            if (first_appear_index.count(num) == 0)   //如果数据没出现过，就记录其索引（第一次出现）
                first_appear_index[num] = i;  
            last_appear_index[num] = i;               //每次都统计
        }
        int max_freq = 0;                               //查找最大频率
        for (auto & it: digit_cnt)
            max_freq = max(max_freq, it.second);

        int res = nums.size();
        for (auto & it: digit_cnt)
        {
            int num = it.first, freq = it.second;
            if (freq == max_freq)    //如果存在很多组满足度相同的，那么需要进行比较，比如：112233
            {
                int cur_len = last_appear_index[num] - first_appear_index[num] + 1;
                res = min(res, cur_len);
            }
        }
        return res;
    }
};
