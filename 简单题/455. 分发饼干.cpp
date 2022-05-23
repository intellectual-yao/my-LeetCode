// Source : https://leetcode-cn.com/problems/assign-cookies/submissions/
// Author ：GuoQiang Yao
// Date : 2021-10-8


/**************************************************************************************
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; 
and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. 
Your goal is to maximize the number of your content children and output the maximum number.

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
 

Constraints:

1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1

**************************************************************************************/


/*******************************************************************************************************
题目分析：本题就是判断两个数组的元素大小情况，故考虑到将两个数组先排序，然后从后向前遍历，
如果饼干数组的最后一个元素大于需求数组的最后一个，就将计数器自增，否则就将需求数组的游标前移，一直到数组遍历结束。
********************************************************************************************************/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //直接排序两个数组，从后向前进行比较
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 饼干数组的下表
        int index = s.size() - 1; 
        int result = 0;
        //从后向前遍历
        for (int i = g.size() - 1; i >= 0; i--) 
        {
            //如果饼干数组的最大元素可以满足孩子胃口，就把result自增并把index自减
            if (index >= 0 && s[index] >= g[i]) 
            {
                result++;
                index--;
            }
        }
        return result;
    }
};
