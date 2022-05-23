// Source : https://leetcode-cn.com/problems/next-greater-element-i/
// Author：GuoQiang Yao
// Date : 2021-10-10

/******************************************************************************************
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and 
determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 

Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.
 

Follow up: Could you find an O(nums1.length + nums2.length) solution?

******************************************************************************************/


/*******************************************************************************************************
题目分析：在nums2中先找到nums1对应的元素下标，然后从该位置向后查找，直到找到第一个比其大的数字，将其放入结果数组
如果查找到最后一个位置都没有元素放入的话，则需要将-1放入结果数组。
********************************************************************************************************/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int j = 0;
        for(int i = 0;i < nums1.size();++i)
        {
            //在nums2中从头开始搜索当前元素的位置
            while(nums2[j] != nums1[i] && j != nums2.size())
                ++j;
            //此时j的位置就是要查找的元素所在的位置
            //假定此时元素是最小的，向后遍历，找到大于它的就放入数组，找不到就放入-1
            int min_nums2 = nums2[j];
            for(j + 1;j < nums2.size();++j)
            {
                if(nums2[j] > min_nums2)
                {
                    res.push_back(nums2[j]);
                    break;
                }
                //当j走到nums2.size-1的位置，还没有进if，说明没找到
                else if(j == nums2.size() - 1)
                    res.push_back(-1);
            }
            j = 0;
        }
        return res;
    }
};
