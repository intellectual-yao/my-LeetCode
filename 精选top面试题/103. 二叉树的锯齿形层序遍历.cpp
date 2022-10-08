// Source : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
// Author : GuoQiang Yao
// Date : 2022-10-8
/**************************************************************************************　　
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：[[3],[20,9],[15,7]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]

提示：

树中节点数目在范围 [0, 2000] 内
-100 <= Node.val <= 100
**************************************************************************************/

/*******************************************************************************************************
题目分析：本题采用了一个比较巧妙的方式，因为每到下一层需要进行逆向存储，
所以我们在每一层的时候对需要存储的下标进行操作，使之可以从后向前存储，
其他的和层序遍历的代码基本没差别。首先入队节点，然后出队节点，当队列不空的时候将队头节点出队，直到队列为空。
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        // 空树的话直接退出
        if(!root)
            return {};
        // 定义循环队列
        queue<TreeNode *> q;
        // 定义flag，标志着本次的内部数组进行正插还是反插
        bool flag = false;
        // 根节点入队
        q.emplace(root);
        // 队列不空的时候进行循环，每次进行本层节点的插入然后入队下一层的节点
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp(size);
            for(int i = 0;i < size;++i)
            {
                // 队头节点出队
                TreeNode *temp_node = q.front();
                q.pop();
                // 判断现在应该是正向还是反向插入元素
                temp[flag ? size -i - 1 : i] = temp_node -> val;
                // 左右子树进队
                if(temp_node -> left)
                    q.emplace(temp_node -> left);
                if(temp_node -> right)
                    q.emplace(temp_node -> right);
            }
            // 每次循环结束之后就应该从另一个方向进行元素的插入，所以flag每次都反向
            flag = !flag;
            res.push_back(temp);
        }
        return res;
    }
};
