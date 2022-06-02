// Source : https://leetcode.cn/problems/generate-parentheses/
// Author : GuoQiang Yao
// Date : 2022-6-1
/**************************************************************************************
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：

输入：n = 3
输出：[“((()))”,“(()())”,“(())()”,“()(())”,“()()()”]
示例 2：

输入：n = 1
输出：[“()”]

提示：

1 <= n <= 8
**************************************************************************************/

/*******************************************************************************************************
题目分析：题解的大佬说道，只要是你觉得需要穷举的方法的话，那么都可以使用回溯法进行求解，
需要注意的是使用递归完成回溯方法的时候要注意递归的结尾条件以及递归之后要将最后的节点抛出来进行右子树节点括号的生成。
********************************************************************************************************/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        dfs(path,0 ,0, n, res);
        return res;
    }

    void dfs(string path,int left, int right, int n, vector<string> &res)
    {
        if(left == n && right == n)
            {
                res.push_back(path);
                return ;
            }
        // 左子树的深度就是[0, n)
        if(left < n)
        {
            // 左子树加左括号
            path += "(";
            // 向下一层，继续递归直到走到对应深度
            dfs(path, left + 1, right, n, res);
            // 返回上一层
            path.pop_back();
        }
        // 当右子树的深度小于左子树的时候就可以继续增加
        if(right < left)
        {
            path += ")";
            // 右子树同样向下增加一层然后通过递归来添加右括号
            dfs(path, left, right + 1, n, res);
            // path.pop_back();
        }
    }
};



// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> res;
//         int lc = 0, rc = 0;
//         dfs(res, "", n, lc, rc);
//         return res;
//     }
//     void dfs(vector<string>& res, string path, int n, int lc, int rc) {
//         if (rc > lc || lc > n || rc > n) return;
//         if (lc == rc && lc == n) {
//             res.push_back(path);
//             return;
//         }
//         dfs(res, path + '(', n, lc + 1, rc);
//         dfs(res, path + ')', n, lc, rc + 1);
//     }
// };  
