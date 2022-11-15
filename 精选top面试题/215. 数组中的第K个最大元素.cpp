// Source :https://leetcode.cn/problems/kth-largest-element-in-an-array/
// Author : GuoQiang Yao
// Date : 2022-11-15
/**************************************************************************************
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1:

输入: [3,2,1,5,6,4], k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4

提示：

1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
**************************************************************************************/

/*******************************************************************************************************
题目分析：第k个最大的元素,快速排序每次的排序结果正好可以将一个元素放在最终位置,而这个最终位置就是第k个最大元素的位置,
因此可以每次进行快速排序,然后比较与k的大小,如果小于k的话说明在右侧,那么left自增,反之right自减.
********************************************************************************************************/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while(true)
        {
            int index = partition(nums, left, right);
            if(index == k - 1)
                return nums[index];
            else if(index < k - 1)
                left = index + 1;
            else
                right = index - 1;
        }
    }
    // 快速排序
    int partition(vector<int> &nums, int left, int right)
    {
        // 选第一个当作枢轴
        int pivot = nums[left];
        while(left < right)
        {
            // 从后向前
            while(left < right && nums[right] <= pivot)
                --right;
            // 左右互补
            nums[left] = nums[right];
            while(left < right && nums[left] >= pivot)
                ++left;
            nums[right] = nums[left];
        }
        // 按照快排，枢轴移动到最终的位置，然后返回该位置
        nums[left] = pivot;
        return left;
    }
};
 
