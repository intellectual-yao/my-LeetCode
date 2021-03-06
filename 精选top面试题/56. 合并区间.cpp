// Source : https://leetcode.cn/problems/merge-intervals/
// Author : GuoQiang Yao
// Date : 2022-6-23
/**************************************************************************************
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

提示：

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

**************************************************************************************/

/*******************************************************************************************************
题目分析：首先对数组进行排序，之后按照合并区间的方式去进行每个区间的端点比较即可，
即比较下一个区间的左端点与当前区间的右端点的大小，
如果下一个区间的左端点小于当前的区间的右端点的话就将新的右端点更新为下一个区间的右端点，然后继续遍历下一个区间，直到遍历完所有的区间
********************************************************************************************************/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 排序
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(int i = 0;i < intervals.size(); )
        {
            // 每个区间的右端点
            int tem = intervals[i][1];
            int j = i + 1;
            // 下一个的左端点小于当前的右端点
            while(j < intervals.size() && intervals[j][0] <= tem)
            {
                // 更新最大的右端点
                tem = max(tem, intervals[j][1]);
                ++j;
            }
            res.push_back({intervals[i][0], tem});
            // 更新i
            i = j;
        }
        return res;
    }
}; 
