// Source : https://leetcode-cn.com/problems/missing-number/
// Author ：GuoQiang Yao
// Date : 2021-10-2


/**************************************************************************************
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
Example 4:

Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
**************************************************************************************/


/*******************************************************************************************************
题目分析：该题算是较容易的一道leetcode问题，单层for循环可以解决，因此不用担心超时问题，
算法思想就是直接从数组的大小开始向前遍历，依次在数组中查找是否存在该值，
存在的话就继续向前查找，不存在的话直接将该值返回即可。
********************************************************************************************************/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //计算出数组的长度即区间的右端点
        int len = nums.size();
        for(int i = len;i >= 0;--i)
        {
            //从后向前,查找该值
            vector<int>::iterator res = find( nums.begin( ), nums.end( ), i); 
            //没找到,返回该值
            if (res == nums.end()) 
                return i;
            //找到了就继续查找下一个
            else 
                continue;
        }
        return 0;
    }
};
