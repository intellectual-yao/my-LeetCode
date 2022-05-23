// Source : https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
// Author : GuoQiang Yao
// Date : 2022-2-21

/**************************************************************************************
给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

示例 1：
输入: root = [5,3,6,2,4,null,7], k = 9
输出: true
示例 2：


输入: root = [5,3,6,2,4,null,7], k = 28
输出: false

提示:

二叉树的节点个数的范围是 [1, 104].
-104 <= Node.val <= 104
root 为二叉搜索树
-105 <= k <= 105

**************************************************************************************/

/*******************************************************************************************************
题目分析：本题类似于数组中搜索是否有两个元素之和满足一定关系的哪一类，不过题目没有直接给出是数组，
而是用BST进行数据的整理，因此我们需要从BST中将数据拿出，因为中序遍历BST可以拿到有序的数组，
因此我们可以对有序的数组进行双指针的操作，从而该题很容易就被解决。
********************************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    //中序遍历将数据都放进数组中
    void inorder_traversal(TreeNode* node, vector<int>& nums)
    {
        if (node == nullptr)
            return;
        inorder_traversal(node->left, nums);
        nums.push_back(node->val);
        inorder_traversal(node->right, nums);
    }
    //利用双指针查找是否存在符合题意的元素
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> nums;
        inorder_traversal(root, nums);
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            //利用sum来保存左右指针所指位置上元素之和
            int sum = nums.at(left) + nums.at(right);
            if (sum == k)
            {
                return true;
            }
            else if (sum > k)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }
        return false;
    }
};
