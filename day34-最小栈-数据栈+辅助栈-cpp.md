@[TOC](LeetCode-day34-最小栈-数据栈+辅助栈-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/min-stack/)

设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

- push(x) -- 将元素 x 推入栈中。
- pop() -- 删除栈顶的元素。
- top() -- 获取栈顶元素。
- getMin() -- 检索栈中的最小元素。

示例:

`MinStack minStack = new MinStack();`
`minStack.push(-2);`
`minStack.push(0);`
`minStack.push(-3);`
`minStack.getMin();   --> 返回 -3.`
`minStack.pop();`
`minStack.top();      --> 返回 0.`
`minStack.getMin();   --> 返回 -2.`





## 题解

> 参考[题解](https://leetcode-cn.com/problems/min-stack/solution/zui-xiao-zhan-by-gpe3dbjds1/)
> 执行用时：$56 ms$ 

**数据栈+辅助栈**

使用了STL库，一个数据栈用于存储所有的数据，另一个辅助栈，只用于存储，每次遇到更小的，就压栈，这样保证辅助栈里是当前最小值。

## cpp代码1

```c++
class MinStack {
public:
    stack<int> s;
    stack<int> min;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(min.empty()||x<=min.top()){
            min.push(x);
        }
    }
    
    void pop() {
        if(s.top()==min.top()){
            min.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();        
    }
    
    int getMin() {
        return min.top(); 
    }
};
```

