// Source : https://leetcode.cn/problems/3sum-closest/
// Author : GuoQiang Yao
// Date : 2022-5-16

/**************************************************************************************
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

示例 1：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
示例 2：

输入：nums = [0,0,0], target = 1
输出：0

提示：

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-10 ^ 4 <= target <= 10 ^ 4
**************************************************************************************/

/*******************************************************************************************************
题目分析： 首先考虑枚举第一个元素 a，对于剩下的两个元素 b 和 c，我们希望它们的和最接近target - a，
每次都使用两者与target的差值进行比较即可，保留较小的哪个即为最终需要返回的求和结果。
********************************************************************************************************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        // 转化为两数之和问题
        for(int i = 0;i < nums.size() - 2;++i)
        {
            // 定义左右指针
            int right = nums.size() - 1;
            int left = i + 1; 
            while(left < right)
            {
                int temp = nums[left] + nums[right] + nums[i];
                if(temp == target)
                    return temp;
                // 如果符合下面条件，说明res太大了，应该用新计算的temp更新之
                if(abs(res - target) > abs(temp - target))
                    res = temp;
                if(temp > target)
                    --right;
                if(temp < target)
                    ++left;
            }
        }
        return res;
    }
}; 
