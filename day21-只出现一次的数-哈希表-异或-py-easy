@[TOC](LeetCode-[136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/single-number)

给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

**说明：**

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

**示例 1:**

```
输入: [2,2,1]
输出: 1
```

**示例 2:**

```
输入: [4,1,2,1,2]
输出: 4
```



## 题解

> 方法二 参考[题解1](https://leetcode-cn.com/problems/single-number/solution/xue-suan-fa-jie-guo-xiang-dui-yu-guo-cheng-bu-na-y/)和[题解2](https://leetcode-cn.com/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-python-by-fei-ben-de-/)，异或
> 时间复杂度是 $O(n)$， 
> 空间复杂度$O(n)->O(1)$,
> 执行用时：$56 ms$ 

题意说明只有1个是单数。

1. 方法一 

   建立哈希表，空间复杂度为O(n)，一次循环用字典存储所有的数的个数，第二个遍历查找为个数为1的，返回该值.

2. 方法二

   异或运算快速找只出现一次的数字。 两个相同的数字做异或运算结果为0；0与非0数字做异或运算结果为非零运算。





## python 哈希表实现

```python
class Solution:
    def singleNumber(self, nums):
        if not nums:
            return None
        dic={}
        for i in range(len(nums)):
            dic[nums[i]]=dic.get(nums[i],0)+1
        for i in range(len(nums)):
            if dic.get(nums[i],0)==1:
                return nums[i]
```



## python 异或实现

```python
class Solution:
    def singleNumber(self, nums):
        singel_num = 0
        for num in nums:
            singel_num ^= num
        return singel_num
```

