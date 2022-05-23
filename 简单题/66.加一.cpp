// Source : https://leetcode-cn.com/problems/plus-one/
// Author : GuoQiang Yao
// Date   : 2021-09-18

/**************************************************************************************
You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [0]
Output: [1]
Explanation: The array represents the integer 0.
Incrementing by one gives 0 + 1 = 1.
Thus, the result should be [1].
Example 4:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.



**************************************************************************************/



/*******************************************************************************************************

题目分析： 本题需要注意的是，解释中说输入数组表示数字xxx，这句话其实跟题目没有关系（笔者傻傻的想办法理解该句话花了好久才发现没啥用），
实际上，本题主要需要处理的是进位问题：当该位上的数字是9的时候，你需要在其前一位上放置一个1，或者将其前一位上的数字值自增1，如果自增以后也达到10了，
那么需要继续向更前方的那一位进行处理。如果你将最后一位的数字值加一之后发现其值并没有达到10，则可以直接返回处理后的数组。

********************************************************************************************************/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; --i )
        {
            if(digits[i] + 1 == 10)
            {
                digits[i] = 0;      //如果某一位数字加一以后等于10，将其置为0
            }
            else
            {
                digits[i] += 1;
                return digits;      //如果某位加一之后不到10，直接返回加一之后的数组即可
            }            
        }
        //如果数组最高位有进位的话，应该在最高位之前放1，然后将处理后的数组元素放入新数组并返回新数组
        vector<int> num;
        num.push_back(1);   //如果初始数据最后只有9，那么在操作之后应该先将1放入新数组，之后将0再放入
        for(int i = 0;i < digits.size();++i)
        {
            num.push_back(digits[i]);
        }
        return num;
    }
};

