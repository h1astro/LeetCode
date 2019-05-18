@[TOC](LeetCode-[20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/valid-parentheses/)

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

**示例 1:**

```
输入: "()"
输出: true
```

**示例 2:**

```
输入: "()[]{}"
输出: true
```

**示例 3:**

```
输入: "(]"
输出: false
```

**示例 4:**

```
输入: "([)]"
输出: false
```

**示例 5:**

```
输入: "{[]}"
输出: true
```



## 题解

> 参考[官方题解](https://leetcode-cn.com/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode/)
> 时间复杂度是 $O(n)$，从头是所有字符串中字符数量的总和。
> 空间复杂度$O(n)$,当我们将所有的开括号都推到栈上时以及在最糟糕的情况下，我们最终要把所有括号推到栈上。例如 `((((((((((`
> 执行用时：$48 ms$

**栈的思想**

如果当前没有匹配到开和关，就将开的符号推入栈中，如果遇到关符号就将栈中的符号推出栈顶元素，匹配是不是一对的，如果不是就返回false结束，否则直到遍历完全部。最后返回栈是不是空的，如果为空说明是有效的括号

![img](https://pic.leetcode-cn.com/Figures/20/20-Valid-Parentheses-Recursive-Property.png)



## python代码实现

```python
class Solution:
    def isValid(self, s: str):
        # 建立一个对应的开闭符号
        mapping={')':'(','}':'{',']':'['}
        # 建一个栈
        stack=[]
        #遍历每个字符
        for char in s:
            #如果存在对应的字典的键时
            if char in mapping:
                #取出栈顶元素，如果为空则返回#
                top=stack.pop() if stack else '#'
                #如果不存在，则返回无效
                if mapping[char]!=top:
                    return False
            #如果不是闭符号，则添加到栈种
            else:
                stack.append(char)
        #stack为空时，说明都匹配完了
        #stack不为空的时候，说明false。
        return not stack
```

