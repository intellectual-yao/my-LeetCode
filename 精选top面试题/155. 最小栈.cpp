// Source : https://leetcode.cn/problems/min-stack/
// Author : GuoQiang Yao
// Date : 2022-11-9
/**************************************************************************************
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。

示例 1:

输入：
[“MinStack”,“push”,“push”,“push”,“getMin”,“pop”,“top”,“getMin”]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); --> 返回 -3.
minStack.pop();
minStack.top(); --> 返回 0.
minStack.getMin(); --> 返回 -2.

提示：

-2^31 <= val <= 2^31 - 1
pop、top 和 getMin 操作总是在 非空栈 上调用
push, pop, top, and getMin最多被调用 3 * 10^4 次
**************************************************************************************/

/*******************************************************************************************************
题目分析 : 使用最小值栈和普通栈作为本题的数据结构。本题初始化的时候在最小值栈中放入INT_MAX，
对于最小值栈每次将栈顶元素和要放入的元素进行比较，将较小的元素放入，每次出栈的时候，
最小值和目标栈同时进行元素的pop，最小值就是最小值栈的栈顶元素。
********************************************************************************************************/

class MinStack {
    stack<int> s;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    // 两个栈同时放入数据，最小值栈只放入最小值
    void push(int val) {
        s.push(val);
        min_stack.push(min(val, min_stack.top()));
    }
    
    void pop() {
        s.pop();
        min_stack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */ 
