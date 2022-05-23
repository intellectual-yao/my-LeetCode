// Source : https://leetcode-cn.com/problems/intersection-of-two-arrays/
// Author ：GuoQiang Yao
// Date : 2021-10-3


/**************************************************************************************
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
**************************************************************************************/



/*******************************************************************************************************
题目分析： 将nums1数组中的元素放入哈希表，然后利用for循环，遍历nums2数组的元素，
采用find函数在哈希表中查找nums2的元素是不是在该哈希表中，在的话就将其添加到目的数组中，
最后将目的数组返回即可。
********************************************************************************************************/

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         //定义两个新容器，将非重复元素放入
//         vector<int> new1 new2, res;
//         //从元素少的数组中取出元素进行比较
//         int nums1_size = nums1.size();
//         int nums2_size = nums2.size();
//         //将两个数组排列成有序的
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
//         for(int i = 0;i < nums1_size - 1;++i)
//         {  
//             //如果前一个与后一个不相等，说明其不是重复元素，将其放入新的vector
//             if(nums1[i] != nums1[i + 1])    
//                 new1.push_back(nums1[i]);
//             //最后两个元素不相等，就把最后一个元素放入vector
//             if(nums1[nums1_size - 2] != nums1[nums1_size - 1])
//                 new1.push_back(nums1[nums1_size - 1]);
//         }
//         for(int i = 0;i < nums2_size - 1;++i)
//         {  
//             //如果前一个与后一个不相等，说明其不是重复元素，将其放入新的vector
//             if(nums2[i] != nums2[i + 1])    
//                 new2.push_back(nums2[i]);
//             //最后两个元素不相等，就把最后一个元素放入vector
//             if(nums2[nums2_size - 2] != nums2[nums2_size - 1])
//                 new2.push_back(nums2[nums2_size - 1]);
//         }
//         int new1_size = new1.size();
//         int new2_size = new2.size();
//         for(int i = 0;i < min(nums1_size, nums2_size) - 1;++i)
//         {
//             for(int j = 0;j < min(nums1_size, nums2_size) - 1;++j)
//             {
//                 if(new1[i] == new2[j])
//                     res.push_back(new1[i]);
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果
        //将nums1元素放入hash表
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        //挨个比较nums2中的元素与nums1中的元素
        for (int num : nums2) {
            // 发现nums2的元素就将其插入到最终的vector中
            if (nums_set.find(num) != nums_set.end())
                result_set.insert(num);
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
