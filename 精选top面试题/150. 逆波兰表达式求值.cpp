// Source : https://leetcode.cn/problems/evaluate-reverse-polish-notation/
// Author : GuoQiang Yao
// Date : 2022-11-9
/**************************************************************************************
根据 逆波兰表示法，求表达式的值。有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
注意 两个整数之间的除法只保留整数部分。
可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：

输入：tokens = [“2”,“1”,“+”,“3”,“*”]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：

输入：tokens = [“4”,“13”,“5”,“/”,“+”]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
示例 3：

输入：tokens = [“10”,“6”,“9”,“3”,“+”,“-11”,““,”/“,””,“17”,“+”,“5”,“+”]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

提示：

1 <= tokens.length <= 104
tokens[i] 是一个算符（“+”、“-”、“*” 或 “/”），或是在范围 [-200, 200] 内的一个整数

逆波兰表达式：

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
逆波兰表达式主要有以下两个优点：

去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
**************************************************************************************/

/*******************************************************************************************************
题目分析 : 本题的解法还是比较简单，定义栈，然后每次将元素入栈，并进行判断，
如果是元素的话就需要进行char与int的转换，然后每次从栈顶取出两个元素，进行计算，
计算结果放入到栈顶，然后继续进行读入，最终结果会被放在栈顶。
********************************************************************************************************/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        int size = tokens.size();
        for(int i = 0;i < size;++i)
        {
            // 取出当前的字符
            string &ch = tokens[i];
            // 如果当前元素是数字的话，就将其从字符类型转为整形，然后入栈
            if(isNumber(ch))
                s.push(atoi(ch.c_str()));
            else
            {
                // 最上面的两个数字就是需要进行运算的，第一个出栈的是运算符右侧的数字，第二个是左测的
                // 如果使用Int类型的话会导致某些计算出错，即溢出，因此使用long来进行元素类型的定义
                long num2 = s.top();
                s.pop();
                long num1 = s.top();
                s.pop();
                switch(ch[0])
                {
                    case '+':
                        s.push(num1 + num2);
                        break;
                    case '-':
                        s.push(num1 - num2);
                        break;
                    case '*':
                        s.push(num1 * num2);
                        break;
                    case '/':
                        s.push(num1 / num2);
                        break;
                }
            }
        }
        // 最终的结果会被存放在栈顶
        return s.top();
    }
    bool isNumber(string &data)
    {
        return !(data == "+" || data == "-" || data == "*" || data == "/");
    }
};
 
