// Source : https://leetcode-cn.com/problems/maximum-product-of-three-numbers/submissions/
// Author：GuoQiang Yao
// Date : 2021-10-11

/******************************************************************************************
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000

******************************************************************************************/

/******************************************************************************************
题目分析：本题首先想到的就是将数据直接排序，然后直接将最后面三个元素乘积返回即可，但是测试的时候
出现了负数的情况，因此会出现最开始的两个数据和最后一个数据乘积大于最后三个元素的乘积，
因此需要将这两种情况的成绩进行比较，将较大的结果返回即可。
******************************************************************************************/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //排序数组
        sort(nums.begin(), nums.end());
        int max1, max2;

        max1 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        max2 = nums[nums.size() - 1] * nums[1] * nums[0];
        if(max1 > max2)
            return max1;  
        else
            return max2;
    }
};
