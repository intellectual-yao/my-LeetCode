// Source :https://leetcode.cn/problems/course-schedule/
// Author : GuoQiang Yao
// Date : 2022-11-13
/**************************************************************************************
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程 bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

示例 1：

输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
示例 2：

输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
输出：false
解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。

提示：

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
prerequisites[i] 中的所有课程对 互不相同
**************************************************************************************/

/*******************************************************************************************************
题目分析：本题使用拓扑排序，将所有的课程组织数组为有向图，通过拓扑排序的原理进行解答，
当节点入度为0的话，就将其加入队列，然后将其产生的边删除，重复操作直到队列为空，每次加入节点的时候都计数，
最后比较计数器与课程数，如果相等则有向图无环，即满足题意反之不满足题意。
********************************************************************************************************/

class Solution {
private:
    vector<vector<int>> edge;
    vector<int> indeg;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        indeg.resize(numCourses);
        // 拿出二维数组中的每一个元素
        for(auto &info : prerequisites)
        {
            // 边节点加入,数据组织形式可知后面的课程是先修课程，因此是向后面的课程中加入前面的课，即从后到前存在路径
            edge[info[1]].push_back(info[0]);
            // 节点对应的入度自增1,后修课程的入度自增1
            ++indeg[info[0]];
        }
        queue<int> q;
        // 将入度为0的节点入队
        for(int i = 0;i < numCourses;++i)
        {
            if(indeg[i] == 0)
                q.push(i);
        }
        // 已经访问的节点数定义
        int visit = 0;
        // 队列非空的时候进行循环
        while(!q.empty())
        {
            ++visit;
            // 队头节点出队
            int up = q.front();
            q.pop();
            // 跟此节点相关的边
            for(int v : edge[up])
            {
                // 入度减一
                --indeg[v];
                // 入度为0的话就加入队列
                if(indeg[v] == 0)
                    q.push(v);
            }
        }
        // 返回遍历到的节点数与课程数的比较
        return visit == numCourses;
    }
}; 
