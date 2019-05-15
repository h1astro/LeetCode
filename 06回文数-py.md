@[TOC](LeetCode-回文数)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/palindrome-number/)

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

**示例 1:**

```
输入: 121
输出: true
```

**示例 2:**

```
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
```

**示例 3:**

```
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
```



## 题解

> 时间复杂度是 $O(log_{10}(n))$
> 空间复杂度$O(1)$
> 执行用时：$132 ms$

对于负数的全不是回文

对于非负数

方法一

> 每整取余10的一个数加到list里，然后依次整除10，跳出循环条件为整除0的时候
>
> 最后通过python可以$list[-i]$的操作,进行前数和尾数一次比较是否相等

方法二

> 也是要整除取余，
>
> 最后反着相乘10，判断得到的数跟之前的是否相同

## py 代码1实现

```cpp
class Solution:
    def isPalindrome(self, x: int) :
        if x<0:
            return False
        count=0
        low=[]
        while x!=0:
            low.append(x%10)
            count=count+1
            x=x//10
        for i in range(count):
            if low[i]!=low[-i-1]:
                return False        
        return True
```

## py 代码2

```python
#借用了别人的代码
class Solution:
    def isPalindrome(self, x: int) :
        if (x < 0) or (x != 0 and x % 10 == 0):
            return False
        cmp_num = 0
        while x > cmp_num:
            cmp_num = cmp_num * 10 + x % 10
            x //= 10
        return x == cmp_num or x == cmp_num // 10
```

