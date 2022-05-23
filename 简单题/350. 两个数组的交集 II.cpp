// Source : https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
// Author ：GuoQiang Yao
// Date : 2021-10-4


/******************************************************************************************
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

******************************************************************************************/


/*******************************************************************************************************
题目分析：先对元素进行排序，相比于该题的第一个版本，此版本可以将两个数组直接排序，然后从头开始遍历两个数组，
它允许元素重复，故当一个数组的对应元素小于另一个数组的元素的时候可以将较小元素所在数组的index向后移动。
继续比较，碰到相等的时候将元素放入最终数组，否则就向后移动对应的Index。
********************************************************************************************************/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //分别排序两个数组
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //求出两个数组的长度
        int length1 = nums1.size(), length2 = nums2.size();
        vector<int> intersection;
        //定义两个下标，分别从0开始
        int index1 = 0, index2 = 0;
        //当下标都合法的时候，把较小元素的下标后移
        while (index1 < length1 && index2 < length2) 
        {
            if (nums1[index1] < nums2[index2]) 
                index1++;
            else if (nums1[index1] > nums2[index2]) 
                index2++;
            //如果二者相等，就将元素放入数组,然后将二者的index同时后移
            else 
            {
                intersection.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }
        return intersection;
    }
};
