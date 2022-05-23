// Source : https://leetcode-cn.com/problems/merge-sorted-array/
// Author : GuoQiang Yao
// Date   : 2021-09-19

/******************************************************************************************
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


******************************************************************************************/


/*******************************************************************************************************

题目分析：  起初想到的是按照单链表的合并操作进行代码编写，也就是把两个数组中有效的数据拿出来，
用两个指针从数组头移动到数组尾部，进行数据的比较，然后按照非递减的顺序放入到nums1数组中，这个操作也可以执行，
但是代码量较大，写起来很复杂，于是就偷偷看了一下官方解法，即直接将两个数组合并（用nums2数组填充nums1数组的0元素），
然后直接调用排序函数进行nums1数组排序（官方真机智哇）。所以此类题，难度并不大，但是一定要注意审题，
本题可以利用nums1数组多余的0元素，在这个条件上做文章。


********************************************************************************************************/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            // if(m == 0)   //如果第一个数组为空，直接将第二个数组的元素放入第一个数组
            // {
            //     for(int i = 0;i < m;++i)
            //     {
            //         nums1[i] = nums2[i];
            //     }
            // }
            // else if(n == 0)     //如果第二个数组为空，直接返回第一个数组
            // {
            //     nums1 = nums1;
            // }
            // else
            // {
            //     //将nums1数组中有效的元素取出至新数组nums3
            //     vector<int> nums3;

            //     for(int i = 0;i < nums1.size() - n;++i)
            //     {
            //         nums3[i] = nums1[i];
            //     }
            //     //将nums3和nums2按照非递减合并之后放入nums1
            //     int j = 0, k = 0, u = 0;
            //     while(u < m && j < nums3.size() && k < nums2.size())
            //     {
            //         if(nums3[j] <= nums2[k])
            //         {
            //             nums1[m] = nums3[j];
            //             ++m;
            //             ++j;    //nums3中的下标后移一位
            //         }
            //         else
            //         {
            //             nums1[m] = nums2[k];
            //             ++m;
            //             ++k;    //nums2中的下标后移一位
            //         }
            //     }

            // }  
            //将nums2先放在nums1之后，然后排序nums1
            for(int i = 0;i < n;++i)
            {
                nums1[m + i] = nums2[i];
            }
            sort(nums1.begin(), nums1.end());
    }
};

