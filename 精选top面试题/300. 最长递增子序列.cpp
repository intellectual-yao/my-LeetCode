// Source :https://leetcode.cn/problems/longest-increasing-subsequence/
// Author : GuoQiang Yao
// Date : 2022-11-30
/**************************************************************************************
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1

提示：

1 <= nums.length <= 2500
-104 <= nums[i] <= 104

进阶：

你能将算法的时间复杂度降低到 O(n log(n)) 吗?
**************************************************************************************/

/*******************************************************************************************************
题目分析：dp[i]表示考虑前i个元素，即dp[i]=max(dp[ j ]) + 1，其中，0 < j < i && num[i] > num[j]，
即考虑往dp[0…i−1] 中最长的上升子序列后面再加一个nums[i]。 因此需要比较dp[ i ]与dp[ j ] + 1的大小，
较大者为dp[ i ]的值。每次需要将dp[ i ]初始化为1，然后进行之后的操作。
********************************************************************************************************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 数组初始化
        vector<int> dp(nums.size(), 0);
        for(int i = 0;i < nums.size();++i)
        {
            dp[i] = 1;
            for(int j = 0;j < i;++j)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
 
