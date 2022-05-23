// Source : https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
// Author：GuoQiang Yao
// Date : 2021-09-20

/******************************************************************************************
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

******************************************************************************************/

/******************************************************************************************

题目分析：本题可以理解为：利用数组画出一颗二叉树，二叉树的高度满足一定的要求（画出的二叉树也是利用数组进行存储），
因此我们可以选择数组中间（或者中间位置的左右两侧）位置作为树根，然后根据这个位置，将数组分为高低两部分，
继续选择每部分的中间（或者中间位置的左右两侧）位置作为树根........依次类推，可以看出：我们可以利用递归来进行树的建立。

******************************************************************************************/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //传入数组、首元素下标、尾元素下标
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // 总是选择中间位置右边的数字作为根节点
        int mid = (left + right + 1) / 2;

        //将该位置的元素做为树根
        TreeNode* root = new TreeNode(nums[mid]);

        //对于左右子树，只需递归调用该函数即可
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        
        //将创建好的root数组返回
        return root;
    }
};



