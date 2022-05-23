// Source : https://leetcode-cn.com/problems/valid-mountain-array/
// Author ：GuoQiang Yao
// Date : 2021-10-22


/**************************************************************************************
Given an array of integers arr, return true if and only if it is a valid mountain array.
Recall that arr is a mountain array if and only if:arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example 1:

Input: arr = [2,1]
Output: false
Example 2:

Input: arr = [3,5,5]
Output: false
Example 3:

Input: arr = [0,3,2,1]
Output: true
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104

**************************************************************************************/



/*******************************************************************************************************
题目分析： 山峰数组，需要最值左右两侧的值依次递减，因此找到最大值之后从两侧开始向中间遍历即可，利用计数器记录
高低子表的符合条件的元素个数，如果加起来是表长则说明符合山峰数组，返回true即可。
********************************************************************************************************/


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        vector<int>::iterator biggest = max_element(begin(arr), end(arr));
        int max_index = distance(begin(arr), biggest);
        //如果最值多次出现，直接返回错误即可
        for(int i = 0;i < arr.size();++i)
            if(arr[i] == *biggest && i != max_index)
                return false;
        //计数器从0开始是为了满足下标
        int low_count = 0;
        int high_count = 1;    
        if(max_index == 0 || max_index == arr.size() - 1)
            return false;
        //从头和尾向中间遍历，看看是否满足题意
        for(int low = 0;low < max_index; ++low)
            if(arr[low] < arr[low + 1])
                low_count++;    
        for(int high = arr.size() - 1;high > max_index;--high)
            if(arr[high] < arr[high - 1])
                high_count++;    
        //看高低子表的长度和是否等于表长
        if(low_count + high_count == arr.size())
            return true;
        else
            return false;
    }
};
