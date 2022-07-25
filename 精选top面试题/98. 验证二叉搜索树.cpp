// Source : https://leetcode.cn/problems/validate-binary-search-tree/
// Author : GuoQiang Yao
// Date : 2022-7-25
/**************************************************************************************　　
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

示例 1：

输入：root = [2,1,3]
输出：true
示例 2：

输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。

提示：

树中节点数目范围在[1, 104] 内
-2^31 <= Node.val <= 23^1 - 1
**************************************************************************************/

/*******************************************************************************************************
题目分析： 一个比较笨的方法就是将元素依次放入数组中，然后遍历数组，如果出现后一个元素大于前一个元素的话就返回false
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
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        mid_search(root, res);
        for(int i = 0;i < res.size() - 1;++i)
        {
            if(res[i] >= res[i + 1])
                return false;
        }
        return true;
    }
    // 中序遍历
    void mid_search(TreeNode *root, vector<int> &res)
    {
        if(root == nullptr)
            return;
        // 中序遍历
        mid_search(root -> left, res);
        res.push_back(root -> val);
        mid_search(root -> right, res);
    }
};
 
