// Source :https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
// Author : GuoQiang Yao
// Date : 2022-11-19
/**************************************************************************************
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

示例 1：


输入：root = [3,1,4,null,2], k = 1
输出：1
示例 2：


输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3

提示：

树中的节点数为 n 。
1 <= k <= n <= 104
0 <= Node.val <= 104
**************************************************************************************/

/*******************************************************************************************************
题目分析：二叉搜索树的中序遍历可以将树中的元素从小到大输出，因此我们使用中序遍历进行求解，
每次循环递减k，当k递减到0时说明当前root指针指向的节点就是所求节点 。
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
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历输出对应的元素即可
        stack<TreeNode*> s;
        while(root || s.size() > 0)
        {
            // 将左子树入栈，全部的左子树入栈，因此需要while
            while(root)
            {
                // 根节点入栈
                s.push(root);
                // 遍历左子树
                root = root  -> left;
            }
            // 根节点出栈
            root = s.top();
            s.pop();
            --k;
            if(k == 0)
                break;
            // 遍历右子树
            root = root  -> right;
        }
        return root -> val;
    }
};
 
