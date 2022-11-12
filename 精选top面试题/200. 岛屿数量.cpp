// Source :https://leetcode.cn/problems/number-of-islands/
// Author : GuoQiang Yao
// Date : 2022-11-12
/**************************************************************************************
给你一个由 ‘1’（陆地）和 ‘0’（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1：

输入：grid = [
[“1”,“1”,“1”,“1”,“0”],
[“1”,“1”,“0”,“1”,“0”],
[“1”,“1”,“0”,“0”,“0”],
[“0”,“0”,“0”,“0”,“0”]
]
输出：1
示例 2：

输入：grid = [
[“1”,“1”,“0”,“0”,“0”],
[“1”,“1”,“0”,“0”,“0”],
[“0”,“0”,“1”,“0”,“0”],
[“0”,“0”,“0”,“1”,“1”]
]
输出：3

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 ‘0’ 或 ‘1’
**************************************************************************************/

/*******************************************************************************************************
题目分析：本题可以使用深度优先遍历，挑选一个位置遍历，然后依次遍历该位置周围四个方向的位置，
如果为1的话就继续遍历此位置的四周，可以发现使用深度优先，如果到达边界条件，就返回0，如果成功遍历，
那么返回1，在主函数中每次遍历之后都需要将计数器自增1，最后返回计数器的值即可。
********************************************************************************************************/

class Solution {
public:
    int dfs(vector<vector<char>> &grid, int i, int j)
    {
        // 边界条件
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return 0;
        // 访问过的地方就标记为0
        grid[i][j] = '0';
        for(int index = 0;index < 4;++index)
        {
            // 下一次访问的位置
            int next_i = i + di[index];
            int next_j = j + dj[index];
            // 深度优先遍历下一个位置
            dfs(grid, next_i, next_j);
        }
        // 成功遍历的话值加一，多少个深度优先，就有多少个岛屿
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0;i < grid.size();++i)
        {
            for(int j = 0;j < grid[0].size();++j)
            {
                cnt += dfs(grid, i, j);
            }
        }
        return cnt;
    }
private:
    // 四个方向的搜索数组
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
}; 
