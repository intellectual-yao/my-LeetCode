// Source :https://leetcode.cn/problems/increasing-triplet-subsequence/
// Author : GuoQiang Yao
// Date : 2022-12-7
/**************************************************************************************
给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。

示例 1：

输入：nums = [1,2,3,4,5]
输出：true
解释：任何 i < j < k 的三元组都满足题意
示例 2：

输入：nums = [5,4,3,2,1]
输出：false
解释：不存在满足题意的三元组
示例 3：

输入：nums = [2,1,5,0,4,6]
输出：true
解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6

提示：

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1

进阶：你能实现时间复杂度为 O(n) ，空间复杂度为 O(1) 的解决方案吗？
**************************************************************************************/

/*******************************************************************************************************
题目分析：三个元素递增，本题思路尽可能使前两个数字尽可能接近，然后每次遍历的时候进行第三个元素的讨论，
如果当前这个元素比first大的话，就需要将second改为当前元素，否则改为first，继续向后遍历，如果出现一个元素比second都大的话说明找到了所求的三元组。
********************************************************************************************************/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0], second = INT_MAX;
        for(int i = 1;i < nums.size(); ++i)
        {
            int tmp = nums[i];
            if(tmp > second)
                return true;
            else if(tmp > first)
                second = tmp;
            else
                first = tmp;
        }
        return false;
    }
};
 
