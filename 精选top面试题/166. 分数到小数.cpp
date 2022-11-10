// Source : https://leetcode.cn/problems/fraction-to-recurring-decimal/
// Author : GuoQiang Yao
// Date : 2022-11-10
/**************************************************************************************
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 104 。

示例 1：

输入：numerator = 1, denominator = 2
输出：“0.5”
示例 2：

输入：numerator = 2, denominator = 1
输出：“2”
示例 3：

输入：numerator = 4, denominator = 333
输出：“0.(012)”

提示：

-231 <= numerator, denominator <= 231 - 1
denominator != 0
**************************************************************************************/

/*******************************************************************************************************
题目分析 : 本题首先要考虑为负数的情况，需要加上负号，其次要判断是否存在小数点后的位数，
如果相除以后可以整除，则直接进行结果返回，如果有小数的话需要进行循环数据的判断，则需要按照数学的角度进行相除。
********************************************************************************************************/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long up = numerator, down = denominator;
        if(up == 0)
            return "0";
        string res;
        long long flag = up * down;
        // 将两个数据全部转为正数进行计算
        up = abs(up);
        down = abs(down);
        // 首先根据flag判断结果的正负，若为负数，将符号加入结果中
        if(flag < 0)
            res.push_back('-');
        if(flag == 0)
            return 0;
        // 把整数部分加入到结果中
        long long pre = up / down;
        res.append(to_string(pre));
        // 处理小数部分，判断是否存在循环           
        long rem = up % down;
        if(rem == 0)
            return res;
        // 小数部分，需要给结果中加上小数点
        else
            res += ".";
        unordered_map<int, int> dict;
        // 如果余数不为0，并且哈希表中没有出现过当前的数字的话
        while(rem != 0 && dict.find(rem) == dict.end())
        {
            // 记录小数点的下标
            dict[rem] = res.size();
            // 按照正常的数学除法进行计算，就是给前面加零作为借位，然后数据乘10进行除法
            res.push_back('0' + rem * 10 / down);
            // 给被除数乘10然后再取余，就相当于进行了下一步的运算
            rem = rem * 10 % down;
        }
        if(rem == 0)
            return res;
        int rep_index = dict[rem];
        res.insert(res.begin() + rep_index, '(');
        res += ")";
        return res;
    }
}; 
