// Source : https://leetcode.cn/problems/subsets/
// Author : GuoQiang Yao
// Date : 2022-7-21
/**************************************************************************************　　
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同
**************************************************************************************/

/*******************************************************************************************************
题目分析：本题使用深度优先遍历，从树根开始向下遍历，碰到叶子节点的时候返回，
最后传出栈顶的元素，然后向右子树进入，继续遍历，直到遍历完所有的子集可能
********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void backtrack(vector<int>& nums,vector<int>&temp,int start) 
    {
        res.push_back(temp);
        for(int i = start;i < nums.size();i++)
        {
            // 深度优先
            temp.push_back(nums[i]);
            backtrack(nums, temp, i + 1);
            // 回溯
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, temp, 0);      
        return res;
    }
}; 
