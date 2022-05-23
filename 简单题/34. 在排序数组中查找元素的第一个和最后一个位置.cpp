// Source : https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author : GuoQiang Yao
// Date : 2022-5-20

/**************************************************************************************
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]

提示：

0 <= nums.length <= 105
-10 ^ 9 <= nums[i] <= 10^9
nums 是一个非递减数组
-10 ^ 9 <= target <= 10 ^ 9
**************************************************************************************/

/*******************************************************************************************************
题目分析： 本题小编采用最简单的分类讨论的方法完成，并没有按照二分法去做，思路较为简单，首先统计相同元素的出现次数，然后按照出现次数的不同进行下一个步骤的操作。
********************************************************************************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int cnt = 0;
        res.push_back(-1);
        res.push_back(-1);
        if(nums.size() == 0)
            return res;
        // 统计相同元素的出现次数
        for(int i = 0;i < nums.size();++i)
            if(nums[i] == target)
                ++cnt;
        // 如果只出现一次，那么起始位置就是最终位置
        if(cnt == 1)
        {
            for(int i = 0;i < nums.size();++i)
            {
                if(nums[i] == target)
                {
                    res[0] = i;
                    res[1] = i;
                }
            }
        }
        else if(cnt == 2)
        {
            cnt = 2;
            if(nums.size() >= 2)
            {
                for(int i = 0;i < nums.size();++i)
                {
                    // 如果找到目标值
                    if(nums[i] == target && (cnt == 2 || cnt == 3))
                    {
                        res[cnt - 2] = i;
                        nums[i] = nums[0] - 1;
                        ++cnt;
                    }
                }
            }
        }
        // 当出现次数超过两次的时候直接从左右两侧开始寻找即可
        else if(cnt > 2)
        {
            int left = 0;
            int right = nums.size() - 1;
            if(left < right)
            {
                while(nums[left] != target)
                    ++left;
                while(nums[right] != target)
                    --right;
                res[0] = left;
                res[1] = right;
            }
        }
        else
        {
            res[0] = -1;
            res[0] = -1;
        }
        return res;
    }
}; 
