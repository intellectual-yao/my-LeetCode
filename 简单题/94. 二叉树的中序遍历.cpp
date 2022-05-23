// Source : https://leetcode.cn/problems/binary-tree-inorder-traversal/
// Author : GuoQiang Yao
// Date : 2022-5-23

/**************************************************************************************
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

示例 1：

输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]

提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
**************************************************************************************/

/*******************************************************************************************************
题目分析： 递归方法使用左中右的方式进行遍历即可，需要注意两点是：首先，
传入参数的时候数组应该传入引用而不是直接传入数组，这样会导致最终的结果并不能被带出（也就是最终输出的是一个空数组），
其次是在访问根节点的元素的时候这里使用的是将对应的value值放入数组中。
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
    // 这里的res应该使用引用的方法进行，否则会出现结果为空的情况
    void inorder(TreeNode* root, vector<int> &res)
    {
        // 按照常见的左中右即可进行遍历
        if(!root)
            return ;
        inorder(root->left, res);
        // 这里的访问元素变成了将元素加入结果数组
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
}; 
