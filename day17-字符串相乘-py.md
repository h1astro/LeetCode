@[TOC](LeetCode-[43. 字符串相乘](https://leetcode-cn.com/problems/multiply-strings/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/multiply-strings/)

给定两个以字符串形式表示的非负整数 `num1` 和 `num2`，返回 `num1` 和 `num2` 的乘积，它们的乘积也表示为字符串形式。

**示例 1:**

```
输入: num1 = "2", num2 = "3"
输出: "6"
```

**示例 2:**

```
输入: num1 = "123", num2 = "456"
输出: "56088"
```

**说明：**

1. `num1` 和 `num2` 的长度小于110。
2. `num1` 和 `num2` 只包含数字 `0-9`。
3. `num1` 和 `num2` 均不以零开头，除非是数字 0 本身。
4. **不能使用任何标准库的大数类型（比如 BigInteger）**或**直接将输入转换为整数来处理**。

## 题解

> 参考[题解1](https://leetcode-cn.com/problems/multiply-strings/solution/python-5xing-shu-shi-ji-suan-by-knifezhu/)和[题解2](https://leetcode-cn.com/problems/multiply-strings/solution/jian-dan-de-pythonshi-xian-by-fengkuang-yu/)
> 时间复杂度是 $O(n^2)$， 
> 空间复杂度$O(m+n)$,
> 执行用时：$300 ms$ 

**竖式计算**

> 注意题干意思，不能直接转整数相乘

对字符串的每一位数字进行相乘，最后对所求的数进行，进位和保留一位数字的处理。

此处python代码使用了字典的形式存储字符串相乘的结果，$enumerate(num1[::-1]) $以倒数的形式返回索引下标和值

$res.get(i+j,default)$,获取$i+j$索引下标的值，如果为空，返回$default$的值。

## python代码实现

```python
class Solution:
    def multiply(self, num1, num2):
        len1=len(num1)
        len2=len(num2)
        res={}
        for i,n1 in enumerate(num1[::-1]):
            for j,n2 in enumerate(num2[::-1]):
                r=int(n1)*int(n2)
                res[i+j]=res.get(i+j,0)+r
                # r2=res.get(i+j,0)+r%10
                # res[i+j]=r2%10
                # if r2//10:
                #     res[i+j+1]=res.get(i+j+1,0)+1
                # if r//10:
                #     res[i+j+1]=res.get(i+j+1,0)+r//10                
        for i in range(len(res)):     #处理每位只能是一位数字和进位
            if res[i]//10:
                res[i+1]=res.get(i+1,0)+res[i]//10    
            res[i]=res[i]%10
        if res[len(res)-1]==0:        #如果得出的整数为"000"之类的情况
            return "0"
        data=""
        for i in range(len(res)):	  #拼接字符串
            data=data+str(res[len(res)-1-i])

        return data
```
