// Source : https://leetcode.cn/problems/word-search/
// Author : GuoQiang Yao
// Date : 2022-7-22
/**************************************************************************************　　
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例 1：


输入：board = [[“A”,“B”,“C”,“E”],[“S”,“F”,“C”,“S”],[“A”,“D”,“E”,“E”]], word = “ABCCED”
输出：true
示例 2：


输入：board = [[“A”,“B”,“C”,“E”],[“S”,“F”,“C”,“S”],[“A”,“D”,“E”,“E”]], word = “SEE”
输出：true
示例 3：


输入：board = [[“A”,“B”,“C”,“E”],[“S”,“F”,“C”,“S”],[“A”,“D”,“E”,“E”]], word = “ABCB”
输出：false

提示：

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board 和 word 仅由大小写英文字母组成
**************************************************************************************/

/*******************************************************************************************************
题目分析： 首先遍历全部的元素找到与目标字符串首字符相同的元素,然后开始在其上下左右进行寻找下一个字符.
********************************************************************************************************/
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i < board.size();++i)
        {
            for(int j = 0;j < board[0].size();++j)
            {
                if(dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    // u是当前查找的字符对应于word里面的位置（index）
    bool dfs(vector<vector<char>> &board, string word, int u, int i, int j)
    {
        if(board[i][j] != word[u])
            return false;
        if(u == word.size() - 1)
            return true;
        // 对用过的元素进行替换防止再一次使用
        char tmp = board[i][j];
        board[i][j] = '-';
        for(int k = 0;k < 4;++k)
        {
            // 上下左右进行搜索
            int a = i + dx[k];
            int b = j + dy[k];
            // 如果当前的范围越界，就选择下一个位置进行判断
            if(a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '-')
                continue;
            if(dfs(board, word, u + 1, a, b))
                return true;            
        }
        // 回溯，将填充的-(特殊符号)变回去
        board[i][j] = tmp;
        return false;
    }
};
 
