// Source : https://leetcode-cn.com/problems/contains-duplicate-ii/
// Author ：GuoQiang Yao
// Date : 2021-09-30


/******************************************************************************************
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k. 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

******************************************************************************************/


/*******************************************************************************************************

题目分析：首先还是想通过改进的双重for循环解决问题，即，内层for循环只走到k的大小，但是依旧显示超时，
因此必须更换方法，考虑使用hash表进行已有元素及其对应下标的存储，然后继续向后遍历数组，如果碰到与当前
数据相同的数据，就计算二者下标的差值的绝对值，如果小于等于k，就返回true，
否则继续将该元素的下标存入hash表（也就是覆盖掉之前的<key, index>以备下一次查找使用）。

********************************************************************************************************/

// hash表查找元素是否存在于表中的方法
// 若有unordered_map <int, int> mp;查找x是否在map中
//     方法1:  若存在  mp.find(x)!=mp.end()
//     方法2:  若存在  mp.count(x)!=0

class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        map<int, int> hash;
        for(int i = 0; i < nums.size(); ++i) 
        {
            //如果元素不在哈希表中，就将元素放入哈希表，并放入其下标，即哈希表组织结构为<key, index>
            if(hash.find(nums[i]) == hash.end()) 
                hash[nums[i]] = i;
            else 
            {
                //如果差值绝对值小于k，返回true
                if(abs(hash[nums[i]] - i) <= k) 
                    return true;
                //如果差值过大，则将该元素以及对应的下标继续存入哈希表
                //以便继续查找之后会不会存在index小于等于k的情况
                else 
                    hash[nums[i]] = i;
            }
        }
        return false;
    }
}; 
        //如愿以偿超时

        // for(int i = 0;i < nums.size() - 1;++i)
        // {
        //     int count = 0;
        //     for(int j = i + 1;count < k && j < nums.size();++j, ++count)
        //     {
        //         //滑动窗口的大小就是count
        //         if(nums[i] == nums[j])
        //             return true;
        //     }
        // }
        // return false;
