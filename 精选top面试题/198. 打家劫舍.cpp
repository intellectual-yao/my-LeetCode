// Source :https://leetcode.cn/problems/house-robber/
// Author : GuoQiang Yao
// Date : 2022-11-11
/**************************************************************************************
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
偷窃到的最高金额 = 1 + 3 = 4 。
示例 2：

输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
偷窃到的最高金额 = 2 + 9 + 1 = 12 。

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 400
**************************************************************************************/

/*******************************************************************************************************
题目分析：本题较为简单，首先考虑状态转移方程，然后考虑边界条件，之后只需要对原来的数据进行状态转移方程的使用即可。
算法思路：如果房屋数量大于两间，对于第 k (k>2) 间房屋，有两个选项：偷窃第k 间房屋，那么就不能偷窃第k−1 间房屋，
偷窃总金额为前 k−2 间房屋的最高总金额与第 kk 间房屋的金额之和。不偷窃第 k 间房屋，偷窃总金额为前k−1 间房屋的最高总金额。
在两个选项中选择偷窃总金额较大的选项，该选项对应的偷窃总金额即为前 k 间房屋能偷窃到的最高总金额。
对于边界条件，如果只有一个房屋，那么dp[0] = nums[0],如果有两个房屋，那么dp[1] = max(nums[0], nums[1])。最终答案为dp[nums.size() - 1]。
********************************************************************************************************/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int size = nums.size();
        if(size == 1)
            return nums[0];
        // 动态规划数组初始化
        vector<int> dp = vector<int>(size, 0);
        // 边界条件
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < size; ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return dp[size - 1];
    }
};
