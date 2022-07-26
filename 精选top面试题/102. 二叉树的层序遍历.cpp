// Source : https://leetcode.cn/problems/binary-tree-level-order-traversal/
// Author : GuoQiang Yao
// Date : 2022-7-26
/**************************************************************************************　　
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

示例 1：



输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]

提示：

树中节点数目在范围 [0, 2000] 内
-1000 <= Node.val <= 1000
**************************************************************************************/

/*******************************************************************************************************
题目分析：本题使用最常规的队列进行广度优先遍历即可，首先将根节点入队，如果有左右子树，
则需要将根节点出队然后将左右子树入队，直到队列为空即可停止。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue <TreeNode *> my_q;
        if(!root)
            return res;
        my_q.push(root);
        // 当队列不为空的时候进入循环，依次放入节点
        while(!my_q.empty())
        {
            // 不同层，节点个数不同，因此每次需要求节点个数
            int cur_size = my_q.size();
            // 二维数组初始化
            res.push_back(vector<int> ());
            // 先将当前节点的值放入二维数组中
            for(int i = 0;i < cur_size;++i)
            {
                auto cur_node = my_q.front();
                // 栈顶元素抛出
                my_q.pop();
                // 二维数组末尾插入元素
                res.back().push_back(cur_node -> val);
                // 左右子树进队
                if(cur_node -> left)
                    my_q.push(cur_node -> left);
                if(cur_node -> right)
                    my_q.push(cur_node -> right);
            }
        }
        return res;
    }
};
 
