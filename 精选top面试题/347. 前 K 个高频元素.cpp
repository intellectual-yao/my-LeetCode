// Source :https://leetcode.cn/problems/top-k-frequent-elements/
// Author : GuoQiang Yao
// Date : 2022-12-6
/**************************************************************************************
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]

提示：

1 <= nums.length <= 105
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的

进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
**************************************************************************************/

/*******************************************************************************************************
题目分析： 本题使用哈希表存储元素的出现次数，然后对次数进行排序，输出前k大，但是考虑到时间复杂度，
还是使用堆进行排序的处理，此处需要考虑的就是大顶堆与小顶堆的取舍，关于取舍，可以看代码部分。然后把堆中的元素全部输出即可。
********************************************************************************************************/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 哈希表存储元素以及对应次数
        unordered_map<int, int> hash;
        for(auto &i : nums)
            ++hash[i];
        // 为了自定义优先队列，实现次数的排序
        struct my_cmp
        {
            // 建立小顶堆，小顶堆是大于号
            bool operator()(pair<int, int> &p, pair<int, int>q)
            {
                return p.second > q.second;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, my_cmp> pri_q;
        for(auto &i : hash)
        {
            // 元素加入优先队列
            pri_q.push(i);
            // 小顶堆每次会把最小的元素弹出，剩下的就是前k个最大的元素，因此使用小顶堆不是大顶堆
            if(pri_q.size() > k)
                pri_q.pop();
        }
        vector<int> res;
        while(!pri_q.empty())
        {
            res.emplace_back(pri_q.top().first);
            pri_q.pop();
        }
        return res;
    }
};
 
