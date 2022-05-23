// Source : https://leetcode-cn.com/problems/max-consecutive-ones/
// Author ：GuoQiang Yao
// Date : 2021-10-9


/**************************************************************************************
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

**************************************************************************************/



/*******************************************************************************************************
题目分析： 首先设置最大值和计数器，当数组中出现1的时候就把计数器自增，如果出现0，就把计数器归零，以便下次出现1的时候
可以重新自增，每次自增结束以后判断现在的计数器和最大值的大小，如果现在的计数器大于最大值，则需要更新最大值，最终
遍历结束，将最大值返回即可。
********************************************************************************************************/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int max = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            //如果数据为1，就将计数器自增
            if (nums[i] == 1)
            {
                count++;
                //如果计数器大于max,就更新
                if (count > max) 
                    max = count;
            } 
            //如果数据不是1，就把count归零
            else
                count = 0;
        }
        return max;
    }
};
