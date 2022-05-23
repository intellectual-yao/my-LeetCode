// Source : https://leetcode-cn.com/problems/third-maximum-number/submissions/
// Author：GuoQiang Yao
// Date : 2021-10-6


/******************************************************************************************
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Can you find an O(n) solution?
******************************************************************************************/


/*******************************************************************************************************
题目分析：将数组从大到小排序，然后利用计数器记录是否找到了第三大数字，因为可能存在同一个元素多次出现，
此时第三大就需要向后找直到找到不相同的元素，否则就说明该数组元素不足三个，直接返回排序结束后的第一个元素即可。
********************************************************************************************************/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //greater：从大到小排序
        sort(nums.begin(), nums.end(), greater<>());
        for (int i = 1, count = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] && ++count == 3) { 
                // 此时 nums[i] 就是第三大的数
                return nums[i];
            }
        }
        //如果上面没有返回说明元素不够3个，则直接返回第一个元素
        return nums[0];

        // if(nums.size() < 3)
        //     //如果元素个数小于三个，直接返回最大数
        //     return nums[nums.size() - 1];
        // else if(nums.size() == 3)
        //     return nums[0];
        // else
        // {
        //     //"删除"相邻的重复元素
        //     vector<int>::iterator new_end = unique(nums.begin(), nums.end());
	    //     //删除(真正的删除)重复的元素
        //     nums.erase(new_end, nums.end());
        // }
        // return nums[nums.size() - 3];
    }
};
