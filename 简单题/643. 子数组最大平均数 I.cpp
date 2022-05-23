// Source : https://leetcode-cn.com/problems/maximum-average-subarray-i/
// Author：GuoQiang Yao
// Date : 2021-10-13


/******************************************************************************************
You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
Any answer with a calculation error less than 10-5 will be accepted.

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 
Constraints:

n == nums.length
1 <= k <= n <= 10^5
-10^4 <= nums[i] <= 10^4

******************************************************************************************/


/*******************************************************************************************************
题目分析：利用滑动窗口，将窗口内的数据进行加和，窗口的大小就是k的大小，如果下一次的和比当前的和大，就更新最大值，
直到遍历结束，得到的最大值返回即可。
********************************************************************************************************/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        // 初始化 sum,c从初值为0开始累加
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int res = sum;
        for (int i = 1; i + k - 1 < n; i++) {
            // 加上右边新元素，减去左边旧元素
            sum += nums[i + k - 1] - nums[i - 1];
            //将较大值返回
            res = max(res, sum);
        }
        return (double)res / k;
    }
};

// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) 
//     {
//         int max = 0;
//         double sum = 0, ave;
//         if(nums.size() > 1)
//         {
//             for(int i = 0;i <= nums.size() - k;++i)
//             {
//                 sum = 0;
//                 for(int j = i;j < k + i;++j)
//                 {
//                     sum += nums[j];
//                 }
//                 if(sum > max)
//                         max = sum;
//             }
//             ave = sum / k;
//             return ave;
//         }
//         else
//             return nums[0];
//     }
// };
