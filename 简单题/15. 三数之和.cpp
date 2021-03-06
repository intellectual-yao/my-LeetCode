// Source : https://leetcode.cn/problems/3sum/
// Author : GuoQiang Yao
// Date : 2022-5-15

/**************************************************************************************
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]

提示：

0 <= nums.length <= 3000
-10 ^ 5 <= nums[i] <= 10 ^ 5
**************************************************************************************/

/*******************************************************************************************************
题目分析： 小编对本题的想法就是本题可以通过固定第一个数字使其转化为两数和的问题，为了避免三重循环超时的问题出现，
可以使用先排序，然后双指针的办法进行剩余数组元素的遍历，此外还要注意的就是如果当前的数字和上一个数字重复，
那么该解法必定会出现重复（因为两个数字已经重复，第三个数字必定也会重复，那么这个解就重复，这就不符合题目的要求），
因此再每次的元素选取之后需要判断其是不是与上一个数字相同，如果相同的话需要直接判断下一个数字。
********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int i = 0; i < nums.size(); ++i) 
        {
            // 需要和上一次枚举的数不相同
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            // 转为求两数之和问题进行求解
            int target = -nums[i];
            // c 对应的指针初始指向数组的最右端
            int k = nums.size() - 1;
            // 枚举 b
            for (int j = i + 1; j < nums.size(); ++j) 
            {
                // 需要和上一次枚举的数不相同
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;
                // 需要保证 b 的指针在 c 的指针的左侧
                while (j < k && nums[j] + nums[k] > target) 
                    --k;
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (j == k) 
                    break;
                if (nums[j] + nums[k] == target) 
                    ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};  
