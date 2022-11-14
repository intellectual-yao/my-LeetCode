// Source :https://leetcode.cn/problems/course-schedule-ii/
// Author : GuoQiang Yao
// Date : 2022-11-14
/**************************************************************************************
现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，
其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。

例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。

示例 1：

输入：numCourses = 2, prerequisites = [[1,0]]
输出：[0,1]
解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
示例 2：

输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
输出：[0,2,1,3]
解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
示例 3：

输入：numCourses = 1, prerequisites = []
输出：[0]

提示：
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
所有[ai, bi] 互不相同
**************************************************************************************/

/*******************************************************************************************************
题目分析：(本题与LeetCode–207.课程表很像，因此解题流程与207题几乎一致，只是加入了结果数组，来存放已经遍历到的入度为0的课程编号)。
本题使用拓扑排序，将所有的课程数组组织为有向图，通过拓扑排序的原理进行解答，当节点入度为0的话，就将其加入队列，
然后将其产生的边删除，重复操作直到队列为空，每次加入节点的时候都计数，最后比较计数器与课程数，如果相等则有向图无环，即满足题意反之不满足题意。
********************************************************************************************************/

class Solution {
private:
    vector<vector<int>> edge;
    vector<int> indeg;
    vector<int> res;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 边数组及入度数组大小初始化
        edge.resize(numCourses);
        indeg.resize(numCourses);
        for(auto &info : prerequisites)
        {
            // 按照二维数组组织数据到边的二维数组
            edge[info[1]].push_back(info[0]);
            // 下一个节点的入度加一
            ++indeg[info[0]];
        }
        // 定义队列
        queue<int> q;
        // 将入度为0的节点全部加入队列
        for(int i = 0;i < numCourses;++i)
        {
            if(indeg[i] == 0)
                q.push(i);
        }
        // 队列非空的话进行循环
        while(!q.empty())
        {
            // 队头节点出队
            int top = q.front();
            q.pop();
            res.push_back(top);
            // 对于已经出队的节点判断其后的节点，并把本节点相关的出边都删除
            for(int tmp : edge[top])
            {
                // 下一个节点的入度减一
                --indeg[tmp];
                if(indeg[tmp] == 0)
                    q.push(tmp);
            }
        }
        // 如果最终遍历到的课程数与原始的课程数不相等就返回空数组
        if(res.size() != numCourses)
            return {};
        return res;
    }
};
 
