// Source : https://leetcode-cn.com/problems/contains-duplicate/
// Author ：GuoQiang Yao
// Date : 2021-09-28


/******************************************************************************************
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

******************************************************************************************/


/*******************************************************************************************************

题目分析：本题比较简单，最原始的想法就是直接采用双重for循环暴力解决问题，但是自打上次for循环修改了一个小时的惨痛教训以后，
leetcode看起来很排斥双重for循环，因此只能换思路。由于本题是判断一个数有没有重复出现，因此考虑到将数组排序，
然后判断相邻的元素是否相等，此时只需要一个for循环即可完成任务，故不会存在超时现象，且排序的时间复杂度也没有
达到平方级，故通过测试。

********************************************************************************************************/


class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        //先排序，然后查看两两相邻的元素是否相等
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0;i < len - 1;++i)
        {
            if(nums[i] == nums[i + 1])
                return true;
        }
        return false;
        // 暴力法如愿以偿超时
        // //求解出数组长度
        // int len = nums.size();
        // for(int i = 0;i < len;++i)
        // {
        //     for(int j = i + 1;j < len;++j)
        //     {
        //         if(nums[i] == nums[j])
        //             return true;
        //     }
        // }
        // return false;
    }
};
