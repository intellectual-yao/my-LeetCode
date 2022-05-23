// Source : https://leetcode.cn/problems/4sum/submissions/
// Author : GuoQiang Yao
// Date : 2022-5-17

/**************************************************************************************
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组
[nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]

提示：

1 <= nums.length <= 200
-10^9 <= nums[i] <= 10 ^9
-10^9 <= target <= 10 ^9

**************************************************************************************/

/*******************************************************************************************************
题目分析： 本题的大致解法与三数之和类似，区别就是要进行两次相同数字的筛选，
最后将其转化为两数求和问题，另外，由于测试用例的限制，需要判断数组中的元素个数以及数组元素的长度，
比如int类型的求和会导致Int型变量不能容纳，因此需要使用long型的数字进行存储结果，然后进行比较。
********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        // 因为测试用例需要
        if(nums.size() < 4)
            return res;
        int length = nums.size();
        for(int i = 0;i < nums.size() - 3; ++i)
        {
            // 去重
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            // 因为测试用例需要（long）
            // 会有特殊测试用例导致结果出现误差，因此当大于目标值的时候需要退出循环
            // 如果前四个就比目标值大，说明不存在符合要求的，直接退出
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) 
                break;
            // 如果四个数字的和小于目标值，则需要继续循环
            if((long)nums[i] + nums[length - 1]+ nums[length - 2] + nums[length - 3] < target)
                continue;
            // 下面代码与三数之和很相似
            for(int j = i + 1;j < length - 2;++j)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                // 会有特殊测试用例导致结果出现误差，因此当大于目标值的时候需要退出循环
                // 如果前四个就比目标值大，说明不存在符合要求的，直接退出
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) 
                    break;
                if ((long)nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) 
                    continue;
                // 下面的代码与两数之和相类似
                int left = j + 1, right = nums.size() - 1;
                while(left < right)
                {
                    int temp = nums[i] + nums[j] + nums[left] + nums[right];
                    // 如果相等的话也可以继续寻找符合要求的值，而不是直接退出
                    if(temp == target)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 缩小查找区间
                        while(left < right && nums[left] == nums[left + 1])
                            ++left;
                        // 当前位置的left,right已经使用，因此这两个指针都需要向内移动
                        ++left;
                        while(left < right && nums[right] == nums[right - 1])
                            --right;
                        --right;
                    }
                    // 如果目前的求和小于目标值，则左下标右移，反之右下标左移
                    else if(temp < target)
                        ++left;
                    else
                        --right;
                }
            }
        }
        return res;
    }
};
