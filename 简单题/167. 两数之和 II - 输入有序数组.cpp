// Source : https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
// Author ：GuoQiang Yao
// Date : 2021-09-26


/******************************************************************************************
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number.
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= first < second <= numbers.length.

Return the indices of the two numbers, index1 and index2, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3.
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2.
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.

******************************************************************************************/


/*******************************************************************************************************

题目分析：一开始小编就想到使用暴力法直接两个for循环遍历数组找到满足题意的答案，但是很遗憾，直接超时警告，
因此，刷LeetCode的时候不到万不得已不能使用for循环，否则一定会产生超时错误。改进的双层for循环，
利用了target来缩短for循环的终止条件，但是还是报错，最终想到了双指针法，low从数组头开始向后遍历，
high从数组尾开始向前遍历，如果low与high位置上的元素相加以后大于target，说明high对应的元素较大，
因此需要左移high，反之说明low对应的元素较小，需要右移low，直到找到符合题意的low与high。

********************************************************************************************************/

class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {

        // //最原始的想法，但是运行超时
        // //定义长度为2的数组
        // vector<int> res;
        // for(int i = 0;i < numbers.size();++i)
        // {
        //     //每一个元素都与其后所有的元素做加法，看有没有满足题意得两个数
        //     for(int j = i + 1;j < numbers.size();++j)
        //     {
        //         if(numbers[i] + numbers[j] == target)
        //         {
        //             //如果满足条件就将i与j加入到向量中
        //             res.push_back(i + 1);
        //             res.push_back(j + 1);
        //         }
        //     }
        // }
        // return res;

        
        //暴力法失败之后的改进暴力法，依旧产生超时问题
        // vector<int> res;
        // int count = 0;      //定义计数器
        // if(target > 0)
        // {
        //     for(int i = 0;i < numbers.size(); ++i)
        //     {
        //         if(numbers[i] <= target && target > numbers[0])
        //         {
        //             count++;
        //         }
        //     }
        //     //在新的长度计算满足条件的情况
        //     int num_size = count;
        //     for(int i = 0;i < num_size;++i)
        //     {
        //         //每一个元素都与其后所有的元素做加法，看有没有满足题意得两个数
        //         for(int j = i + 1;j < num_size;++j)
        //         {
        //             if(numbers[i] + numbers[j] == target)
        //             {
        //                 //如果满足条件就将i与j加入到向量中
        //                 res.push_back(i + 1);
        //                 res.push_back(j + 1);
        //             }
        //         }
        //     }
        //     return res;
        // }
        // else
        // {
        //     for(int i = 0;i < numbers.size();++i)
        //     {
        //         //每一个元素都与其后所有的元素做加法，看有没有满足题意得两个数
        //         for(int j = i + 1;j < numbers.size();++j)
        //         {
        //             if(numbers[i] + numbers[j] == target)
        //             {
        //                 //如果满足条件就将i与j加入到向量中
        //                 res.push_back(i + 1);
        //                 res.push_back(j + 1);
        //             }
        //         }
        //     }
        //     return res;
        // }
       
       int low = 0, high = numbers.size() - 1;
       while(low < high)
       {
           if(numbers[low] + numbers[high] > target)
                high--;
            else if(numbers[low] + numbers[high] < target)
                low++;
            else
                break;
       } 
       return vector<int>{low + 1, high + 1};
    }
};
