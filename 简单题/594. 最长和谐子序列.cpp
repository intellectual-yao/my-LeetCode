// Source : https://leetcode-cn.com/problems/longest-harmonious-subsequence/
// Author ：GuoQiang Yao
// Date : 2021-10-23


/******************************************************************************************
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Example 2:

Input: nums = [1,2,3,4]
Output: 2
Example 3:

Input: nums = [1,1,1,1]
Output: 0
 

Constraints:

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109

******************************************************************************************/


/*******************************************************************************************************
题目分析：本题利用尺取法，尺取法通常是对数组保存一对下标，即所选取的区间的左右端点，然后根据实际情况不断地推进区间左右端点以得出答案。
本题在绝对值之差大于1的时候需要移动指针，按照此条件先移动右指针在移动左指针，然后用max函数找出最大值进行返回即可。
********************************************************************************************************/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());  //排序
        int n = nums.size();
        int ans = 0, lhs = 0, rhs = 1;
        while(rhs < n)
        {
            while(nums[rhs] < nums[lhs] + 1 && rhs < n - 1) 
                ++rhs;  //右侧最大值不满足
            while(nums[lhs] + 1 < nums[rhs] && lhs < rhs) 
                ++lhs;    //左侧最小值不满足
            if(nums[lhs] + 1 == nums[rhs]) 
            //找出最长的和谐区间
                ans = max(ans,  rhs - lhs + 1);
            rhs++;
        }
        return ans;
    }
};
