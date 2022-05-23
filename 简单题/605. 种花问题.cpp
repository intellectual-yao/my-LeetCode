// Source : https://leetcode-cn.com/problems/can-place-flowers/submissions/
// Author ：GuoQiang Yao
// Date : 2021-10-19

/**************************************************************************************
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

**************************************************************************************/



/*******************************************************************************************************
题目分析：如果一个位置的前后都是0，则该位置可以放花，放了以后将该位置的元素置1即可，但是如果数组最开始或者
末尾都是1的花，在进行判断的时候需要特殊处理，因此需要在末尾以及开始的地方需要填充0，然后从1号位置开始判断，
直到最后一个位置之前的那里即可。
********************************************************************************************************/

class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        //初始化计数器
        int count =  0;
        //在数组前后都填充上0，避免只有一个元素的情况出现
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.insert(flowerbed.end(),0);
        //如果当前位置及其前后位置都是0，则可以种花
        for(int i = 1; i < flowerbed.size()-1; i++)
        {
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
            {
                //如果当前位置可以放，就把该位置置1
                flowerbed[i] = 1;
                count++;
            }
        }
        return n <= count;
    }
};
